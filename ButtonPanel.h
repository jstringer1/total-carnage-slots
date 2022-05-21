#pragma once
#include "Console.h"

enum UserInput {
	SPIN,
	EXIT
};

class ButtonPanel {
public:
	ButtonPanel(Console* console);
	UserInput acceptUserInput();
private:
	void enable();
	void disable();
	Console* console;
};