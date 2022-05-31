#include "ReelPanel.h"
#include "resource.h"
#include <Windows.h>

ReelPanel::ReelPanel(Console* console, int x, int startingPosition) {
	ReelPanel::console = console;
	ReelPanel::x = x;
	ReelPanel::position = startingPosition;
	HRSRC res = FindResource(NULL, MAKEINTRESOURCE(IDR_SYMBOLS), RT_RCDATA);
	char* data = (char*)LockResource(LoadResource(NULL, res));
	symbolData = std::string(data);
}

bool ReelPanel::incrementFrame(bool stopping, SYMBOL stopSymbol) {
	if (!stopping) bounce = NOT_BOUNCING;
	if (stopping && increment == 0 && (SYMBOL)position == stopSymbol && bounce == BOUNCED) return true;
	if (bounce == BOUNCING) {
		increment -= 1;
		bounce = BOUNCED;
	} else {
		increment += 1;
	}
	if (stopping && increment == 1 && (SYMBOL)position == stopSymbol) bounce = BOUNCING;
	if (increment == symbolHeight) {
		increment = 0;
		position += 1;
		if (position == symbolCount) position = 0;
	}
	return false;
}

void ReelPanel::drawCurrentFrame(COLOUR background) {
	for (int y = 0; y < symbolHeight; y++) {
		if (y + symbolHeight + increment >= yMin) drawSymbolLine(symbolId(position+2), symbolHeight, y, COLOUR_BLACK);
		drawSymbolLine(symbolId(position+1), (symbolHeight*2), y, COLOUR_BLACK);
		drawSymbolLine(position, (symbolHeight*3), y, background);
		if (y + (symbolHeight*4) + increment < yMax) drawSymbolLine(symbolId(position-1), (symbolHeight*4), y, COLOUR_BLACK);
	}
}

int ReelPanel::symbolId(int id) {
	if (id == (symbolCount+1)) return 1;
	if (id == symbolCount) return 0;
	if (id == -1) return (symbolCount-1);
	return id;
}

void ReelPanel::drawSymbolLine(int symbol, int symbolOffset, int yOffset, COLOUR background) {
	console->setColourAndPosition(symbolColour[symbol], background, x, yOffset + symbolOffset + increment);
	printf(symbolData.substr(((symbol * symbolWidth) + (symbolDataLineLength * yOffset)), symbolWidth).c_str());
}