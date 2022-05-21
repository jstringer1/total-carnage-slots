#include "Console.h"

Console::Console() {
	in = GetStdHandle(STD_INPUT_HANDLE);
	out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleMode(in, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	SetConsoleMode(out , CONSOLE_FULLSCREEN_MODE);
	SetConsoleOutputCP(CP_UTF8);
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);
}

HANDLE Console::stdIn() {
	return in;
}

HANDLE Console::stdOut() {
	return out;
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

MOUSE_EVENT_RECORD Console::waitForMouseEvent() {
	INPUT_RECORD rec;
	DWORD count = 0;
	while (true) {
		ReadConsoleInput(in, &rec, 1, &count);
		if (rec.EventType == MOUSE_EVENT )  return rec.Event.MouseEvent;
	}
}

COORD Console::waitForMouseClick() {
	while (true) {
		MOUSE_EVENT_RECORD ev = waitForMouseEvent();
		if (ev.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) return ev.dwMousePosition;
	}
}