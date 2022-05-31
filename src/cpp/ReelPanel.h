#pragma once
#include "OutcomeGenerator.h"
#include "Console.h"
#include <thread>
#include <string>

class ReelPanel {
public: 
	ReelPanel(Console* console, int x, int startingPosition);
	bool incrementFrame(bool stopping, SYMBOL stopSymbol);
	void drawCurrentFrame(COLOUR backgroundColour);
private:
	enum BOUNCE_STATE {
		NOT_BOUNCING,
		BOUNCING,
		BOUNCED
	};
	Console* console;
	int x;
	int position;
	int increment = 0;
	std::string symbolData;
	BOUNCE_STATE bounce;
	int yMin = 20;
	int yMax = 50;
	int symbolCount = 6;
	int symbolWidth = 20;
	int symbolHeight = 10;
	int symbolDataLineLength = 122;
	COLOUR symbolColour[6] = { COLOUR_RED, COLOUR_ORANGE, COLOUR_YELLOW, COLOUR_ORANGE, COLOUR_PURPLE, COLOUR_BLUE };
	void drawSymbolLine(int symbol, int symbolOffset, int yOffset, COLOUR background);
	int symbolId(int id);
};