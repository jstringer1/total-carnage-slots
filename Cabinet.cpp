#include "Cabinet.h";
#include "Symbols.h"

Cabinet::Cabinet(Console* console, Wallet* wallet) {
	Cabinet::console = console;
	Cabinet::wallet = wallet;
	Cabinet::buttons =  new ButtonPanel(console);
	console->setPosition(0, 0);
	console->setColour(COLOUR_BRIGHT_WHITE, COLOUR_BLACK);
	for (int i = 0; i < 100; i++) printf("                                                                                                                                               \n");
	onCreditChangeEvent();
	wallet->registerListener(this);
}

Cabinet::~Cabinet() {
	delete buttons;
	wallet->unregisterListener(this);
	console = NULL;
	wallet = NULL;
	buttons = NULL;
}

ButtonPanel* Cabinet::getButtons() {
	return buttons;
}

void Cabinet::onCreditChangeEvent() {
	double balance = wallet->getBalance() / 100.0;
	console->setColourAndPosition(COLOUR_PURPLE, COLOUR_WHITE, 50, 51);
	printf("                  ");
	console->setPosition(50, 51);
	printf(" BALANCE: \xC2\xA3%.2f ", balance);
}

void Cabinet::showSpinningReels(REEL_POSITIONS result) {
	printSymbol(console, result.reel1, 20, 40);
	printSymbol(console, result.reel2, 50, 40);
	printSymbol(console, result.reel3, 80, 40);
}