#include "Cabinet.h"
#include "Symbols.h"
#include "resource.h"

Cabinet::Cabinet(Console* console, Wallet* wallet, SoundController *sound) {
	Cabinet::console = console;
	Cabinet::wallet = wallet;
	Cabinet::sound = sound;
	Cabinet::buttons = new ButtonPanel(console);
	Cabinet::balance = new BalancePanel(console, COLOUR_PURPLE, COLOUR_BLACK, 28, 52);
	console->setColourAndPosition(COLOUR_BLACK, COLOUR_GREY,0,0);
	for (int i = 0; i < 120; i++) printf("                                                                                                                                                                                                                                                                       \n");
	console->setColourAndPosition(COLOUR_BLACK, COLOUR_BLACK, 0, 0);
	for (int i = 0; i < 57; i++) printf("                                                                                                     \n");
	onCreditChangeEvent();
	wallet->registerListener(this);

	console->printResource(IDR_TITLE, COLOUR_PURPLE, COLOUR_BLACK, 0);
	console->printResource(IDR_REELS, COLOUR_GREEN, COLOUR_BLACK, 19);

	printSymbol(console, CHERRY, 15, 40, COLOUR_BLACK);
    printSymbol(console, CHERRY, 42, 40, COLOUR_BLACK);
    printSymbol(console, CHERRY, 69, 40, COLOUR_BLACK);
    printSymbol(console, CHERRY, 15, 30, COLOUR_BLACK);
    printSymbol(console, CHERRY, 42, 30, COLOUR_BLACK);
    printSymbol(console, CHERRY, 69, 30, COLOUR_BLACK);
    printSymbol(console, CHERRY, 15, 20, COLOUR_BLACK);
    printSymbol(console, CHERRY, 42, 20, COLOUR_BLACK);
    printSymbol(console, CHERRY, 69, 20, COLOUR_BLACK);
}

Cabinet::~Cabinet() {
	delete buttons;
	delete balance;
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
	char balancestring[64];
	sprintf_s(balancestring, 64, "£%.2f", balance);

	for (int y = 52; y < 56; y++) {
		console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, 28, y);
		printf("                                                            ");
	}
	Cabinet::balance->printBalance(std::string(balancestring));
}

int reel[3][2] = { {0,0}, {0,0}, {0,0} };

void incrementReelCounter(int index) {
	reel[index][0] += 1;
	if (reel[index][0] == 9) {
		reel[index][0] = 0;
		reel[index][1] += 1;
		if (reel[index][1] == 6) reel[index][1] = 0;
	}
}

SYMBOL toSymbol(int index) {
	if (index == -1) return (SYMBOL)5;
	if (index == 6) return (SYMBOL)0;
	return (SYMBOL)index;
}

void Cabinet::showSpinningReels(OUTCOME result) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 3; k++) {
				incrementReelCounter(k);
			}
			printSymbol(console, toSymbol(reel[0][1]+1), 15, 20 + reel[0][0], COLOUR_BLACK);
			printSymbol(console, toSymbol(reel[1][1]+1), 42, 20 + reel[1][0], COLOUR_BLACK);
			printSymbol(console, toSymbol(reel[2][1]+1), 69, 20 + reel[2][0], COLOUR_BLACK);

			printSymbol(console, toSymbol(reel[0][1]), 15, 30 + reel[0][0], COLOUR_BLACK);
			printSymbol(console, toSymbol(reel[1][1]), 42, 30 + reel[1][0], COLOUR_BLACK);
			printSymbol(console, toSymbol(reel[2][1]), 69, 30 + reel[2][0], COLOUR_BLACK);

			printSymbol(console, toSymbol(reel[0][1]-1), 15, 40 + reel[0][0], COLOUR_BLACK);
			printSymbol(console, toSymbol(reel[1][1]-1), 42, 40 + reel[1][0], COLOUR_BLACK);
			printSymbol(console, toSymbol(reel[2][1]-1), 69, 40 + reel[2][0], COLOUR_BLACK);
			Sleep(25);
		}
	}
	while (((SYMBOL)reel[0][1]) != result.reel1) {
		for (int i = 0; i < 3; i++) incrementReelCounter(i);
		printSymbol(console, toSymbol(reel[0][1] + 1), 15, 20 + reel[0][0], COLOUR_BLACK);
		printSymbol(console, toSymbol(reel[1][1] + 1), 42, 20 + reel[1][0], COLOUR_BLACK);
		printSymbol(console, toSymbol(reel[2][1] + 1), 69, 20 + reel[2][0], COLOUR_BLACK);

		printSymbol(console, toSymbol(reel[0][1]), 15, 30 + reel[0][0], COLOUR_BLACK);
		printSymbol(console, toSymbol(reel[1][1]), 42, 30 + reel[1][0], COLOUR_BLACK);
		printSymbol(console, toSymbol(reel[2][1]), 69, 30 + reel[2][0], COLOUR_BLACK);

		printSymbol(console, toSymbol(reel[0][1] - 1), 15, 40 + reel[0][0], COLOUR_BLACK);
		printSymbol(console, toSymbol(reel[1][1] - 1), 42, 40 + reel[1][0], COLOUR_BLACK);
		printSymbol(console, toSymbol(reel[2][1] - 1), 69, 40 + reel[2][0], COLOUR_BLACK);
		Sleep(25);
	}
	while (((SYMBOL)reel[1][1]) != result.reel2) {
		for (int i = 1; i < 3; i++) incrementReelCounter(i);
		printSymbol(console, toSymbol(reel[1][1] + 1), 42, 20 + reel[1][0], COLOUR_BLACK);
		printSymbol(console, toSymbol(reel[2][1] + 1), 69, 20 + reel[2][0], COLOUR_BLACK);

		printSymbol(console, toSymbol(reel[1][1]), 42, 30 + reel[1][0], COLOUR_BLACK);
		printSymbol(console, toSymbol(reel[2][1]), 69, 30 + reel[2][0], COLOUR_BLACK);

		printSymbol(console, toSymbol(reel[1][1] - 1), 42, 40 + reel[1][0], COLOUR_BLACK);
		printSymbol(console, toSymbol(reel[2][1] - 1), 69, 40 + reel[2][0], COLOUR_BLACK);
		Sleep(25);
	}
	while (((SYMBOL)reel[2][1]) != result.reel3) {
		incrementReelCounter(2);
		printSymbol(console, toSymbol(reel[2][1] + 1), 69, 20 + reel[2][0], COLOUR_BLACK);
		printSymbol(console, toSymbol(reel[2][1]), 69, 30 + reel[2][0], COLOUR_BLACK);
		printSymbol(console, toSymbol(reel[2][1] - 1), 69, 40 + reel[2][0], COLOUR_BLACK);
		Sleep(25);
	}

	if (result.reel1 == result.reel2 && result.reel2 == result.reel3) {
		if (result.reel1 == BELL) sound->playILoveIt();
		else sound->playBigPrizes();
		for (int i = 0; i < 5; i++) {
			printSymbol(console, result.reel1, 15, 30, COLOUR_WHITE);
			printSymbol(console, result.reel2, 42, 30, COLOUR_WHITE);
			printSymbol(console, result.reel3, 69, 30, COLOUR_WHITE);
			Sleep(25);
			printSymbol(console, result.reel1, 15, 30, COLOUR_BLACK);
			printSymbol(console, result.reel2, 42, 30, COLOUR_BLACK);
			printSymbol(console, result.reel3, 69, 30, COLOUR_BLACK);
			Sleep(25);
		}
	} else if (result.reel1 == result.reel2) {
		sound->playBigMoney();
		for (int i = 0; i < 5; i++) {
			printSymbol(console, result.reel1, 15, 30, COLOUR_WHITE);
			printSymbol(console, result.reel2, 42, 30, COLOUR_WHITE);
			Sleep(150);
			printSymbol(console, result.reel1, 15, 30, COLOUR_BLACK);
			printSymbol(console, result.reel2, 42, 30, COLOUR_BLACK);
			Sleep(150);
		}
	}
	else {
		sound->playTotalCarnage();
		Sleep(1000);
	}
}