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
			if (position.X >= 2 && position.X <= 10 && position.Y >= 52 && position.Y <= 54) return EXIT;
			else if (position.X >= 90 && position.X <= 98 && position.Y >= 52 && position.Y <= 54) return SPIN;
		}
	} __finally {

		disable();
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
