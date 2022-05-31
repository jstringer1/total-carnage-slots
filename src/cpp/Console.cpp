#include "Console.h"

Console::Console() {
	in = GetStdHandle(STD_INPUT_HANDLE);
	out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleMode(in, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	SetConsoleMode(out , CONSOLE_FULLSCREEN_MODE);
	SetConsoleOutputCP(CP_UTF8);
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
	running = true;
	userInputThread = std::thread(&Console::processConsoleInput, this);
}

Console::~Console() {
	running = false;
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = true;
	SetConsoleCursorInfo(out, &cursorInfo);
	setColourAndPosition(COLOUR_BRIGHT_WHITE, COLOUR_BLACK, 0, 100);
	userInputThread.join();
}

HANDLE Console::stdIn() {
	return in;
}

HANDLE Console::stdOut() {
	return out;
}

void Console::printResource(int id, COLOUR foreground, COLOUR background, int y) {
	setColourAndPosition(foreground, background, 0, y);
	HRSRC res = FindResource(NULL, MAKEINTRESOURCE(id), RT_RCDATA);
	char* data = (char*)LockResource(LoadResource(NULL, res));
	printf(data);
}

void Console::setColourAndPosition(COLOUR foreground, COLOUR background, int x, int y) {
	setColour(foreground, background);
	setPosition(x, y);
}

void Console::setColour(COLOUR foreground, COLOUR background) {
	SetConsoleTextAttribute(out, foreground + (16 * background));
}

void Console::setPosition(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(out, pos);
}

void Console::registerListener(MouseClickListener* listener) {
	listeners.insert(listener);
}

void Console::unregisterListener(MouseClickListener* listener) {
	listeners.erase(listener);
}

void Console::processConsoleInput() {
	INPUT_RECORD rec;
	DWORD count = 0;
	while (running) {
		GetNumberOfConsoleInputEvents(in, &count);
		if (count == 0) {
			Sleep(100);
		}
		else {
			ReadConsoleInput(in, &rec, 1, &count);
			if (rec.EventType == MOUSE_EVENT && rec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				handleMouseClick(rec.Event.MouseEvent.dwMousePosition);
		}
	}
}

void Console::handleMouseClick(COORD ev) {
	std::set<MouseClickListener*>::iterator it;
	for (it = listeners.begin(); it != listeners.end(); it++)
		(*it)->onMouseClick(ev);
}