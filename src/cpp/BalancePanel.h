#pragma once
#include <map>
#include <string>
#include "Console.h"

struct FONT_DATA {
	int offset;
	int width;
	FONT_DATA() {
		offset = 0;
		width = 0;
	}
	FONT_DATA(int o, int w) {
		offset = o;
		width = w;
	}
};

class BalancePanel {
public:
	BalancePanel(Console* console, COLOUR forground, COLOUR background, int x, int y);
	void printBalance(std::string balance);
private:
	Console* console;
	COLOUR foreground;
	COLOUR background;
	int x;
	int y;
	std::map<char, FONT_DATA> fontData;
	std::string fontSymbolData;
	int fontSymbolDataLineLength;
	int fontHeight;
};