#include "ButtonPanel.h"
#include <Windows.h>

ButtonPanel::ButtonPanel(Console* console) {
	ButtonPanel::console = console;
	disable();
}

UserInput ButtonPanel::acceptUserInput() {
	enable();
	__try {
		while (true) {
			COORD position = console->waitForMouseClick();
			if (position.X >= 10 && position.X <= 18 && position.Y >= 50 && position.Y <= 52) return EXIT;
			else if (position.X >= 100 && position.X <= 108 && position.Y >= 50 && position.Y <= 52) return SPIN;
		}
	} __finally {

		disable();
	}
}

void drawButtons(Console* console) {
	console->setPosition(100, 50);
	printf("        ");
	console->setPosition(100, 51);
	printf("  SPIN  ");
	console->setPosition(100, 52);
	printf("        ");

	console->setPosition(10, 50);
	printf("        ");
	console->setPosition(10, 51);
	printf("  EXIT  ");
	console->setPosition(10, 52);
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
