#include "BalancePanel.h"
#include "resource.h"

BalancePanel::BalancePanel(Console* console, COLOUR foreground, COLOUR background, int x, int y) {
	BalancePanel::console = console;
	BalancePanel::foreground = foreground;
	BalancePanel::background = background;
	BalancePanel::x = x;
	BalancePanel::y = y;

	fontData['0'] = FONT_DATA(0, 8);
	fontData['1'] = FONT_DATA(8, 5);
	fontData['2'] = FONT_DATA(13, 7);
	fontData['3'] = FONT_DATA(20, 6);
	fontData['4'] = FONT_DATA(26, 8);
	fontData['5'] = FONT_DATA(34, 7);
	fontData['6'] = FONT_DATA(41, 8);
	fontData['7'] = FONT_DATA(49, 8);
	fontData['8'] = FONT_DATA(57, 7);
	fontData['9'] = FONT_DATA(64, 8);
	fontData['.'] = FONT_DATA(72, 5);
	fontData['£'] = FONT_DATA(77, 6);
	fontSymbolDataLineLength = 85;
	fontHeight = 4;

	HRSRC res = FindResource(NULL, MAKEINTRESOURCE(IDR_BALANCE), RT_RCDATA);
	char* data = (char*)LockResource(LoadResource(NULL, res));
	fontSymbolData = std::string(data);
}

void BalancePanel::printBalance(std::string balance) {
	console->setColour(foreground, background);
	int xoff = 0;
	for (int i = 0; i < balance.length(); i++) {
		FONT_DATA charData = fontData[balance.at(i)];
		for (int y = 0; y < fontHeight; y++) {
			console->setPosition(x + xoff, BalancePanel::y+y);
			printf(fontSymbolData.substr(charData.offset+(y* fontSymbolDataLineLength), charData.width).c_str());
		}
		xoff += charData.width;
	}
}