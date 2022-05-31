#pragma once
#include "Console.h"
#include <condition_variable>

enum UserInput {
	SPIN,
	EXIT
};

class ButtonPanel : MouseClickListener {
public:
	ButtonPanel(Console* console);
	~ButtonPanel();
	UserInput acceptUserInput();
	virtual void onMouseClick(COORD pos) override;
private:
	void enable();
	void disable();
	Console* console;
	std::condition_variable sync;
	UserInput input;
};