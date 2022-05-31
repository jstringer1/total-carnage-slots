#include "ButtonPanel.h"
#include <Windows.h>
#include <mutex>

ButtonPanel::ButtonPanel(Console* console) {
	ButtonPanel::console = console;
	disable();
	console->registerListener(this);
}

ButtonPanel::~ButtonPanel() {
	console->unregisterListener(this);
}

UserInput ButtonPanel::acceptUserInput() {
	enable();
	std::mutex mtx;
	std::unique_lock<std::mutex> lck(mtx);
	sync.wait(lck);
	disable();
	return input;
}

void ButtonPanel::onMouseClick(COORD pos) {
	if (pos.X >= 2 && pos.X <= 10 && pos.Y >= 52 && pos.Y <= 54) {
		input = EXIT;
		sync.notify_all();
	}
	else if (pos.X >= 90 && pos.X <= 98 && pos.Y >= 52 && pos.Y <= 54) {
		input = SPIN;
		sync.notify_all();
	}
}

void drawButtons(Console* console) {
	console->setPosition(90, 52);
	printf("        ");
	console->setPosition(90, 53);
	printf("  SPIN  ");
	console->setPosition(90, 54);
	printf("        ");

	console->setPosition(2, 52);
	printf("        ");
	console->setPosition(2, 53);
	printf("  EXIT  ");
	console->setPosition(2, 54);
	printf("        ");
}

void ButtonPanel::enable() {
	console->setColour(COLOUR_BRIGHT_WHITE, COLOUR_PURPLE);
	drawButtons(console);
}

void ButtonPanel::disable() {
	console->setColour(COLOUR_BLACK, COLOUR_GREY);
	drawButtons(console);
}
