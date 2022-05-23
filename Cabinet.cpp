#include "Cabinet.h"
#include "Symbols.h"

Cabinet::Cabinet(Console* console, Wallet* wallet, SoundController *sound) {
	Cabinet::console = console;
	Cabinet::wallet = wallet;
	Cabinet::sound = sound;
	Cabinet::buttons =  new ButtonPanel(console);
	console->setColourAndPosition(COLOUR_BLACK, COLOUR_GREY,0,0);
	for (int i = 0; i < 120; i++) printf("                                                                                                                                                                                                                                                                       \n");
	console->setColourAndPosition(COLOUR_BLACK, COLOUR_BLACK, 0, 0);
	for (int i = 0; i < 57; i++) printf("                                                                                                     \n");
	onCreditChangeEvent();
	wallet->registerListener(this);

	printTitle(console, 15, 0);

	console->setColourAndPosition(COLOUR_GREEN, COLOUR_BLACK, 0, 19);
	printf("           ,adPP88888888888888YYba,   ,adPP88888888888888YYba,   ,adPP88888888888888YYba,");
	console->setPosition(0, 20);
	printf("           a8\"                  \"8a   a8\"                  \"8a   a8\"                  \"8a");
	for (int y = 21; y < 49; y++) {
		console->setPosition(0, y);
		printf("           88                    88   88                    88   88                    88");
	}
	console->setPosition(0, 49);
	printf("           \"8a,                ,a8\"   \"8a,                ,a8\"   \"8a,                ,a8\"");
	console->setPosition(0, 50);
	printf("           `\"Yb8888888888888888dP\"'    \"Yb8888888888888888dP\"'    \"Yb8888888888888888dP\"'");

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
	sprintf_s(balancestring, 64, "%.2f", balance);
	
	std::string line1 = " dp\"Yb";
	std::string line2 ="8888  ";
	std::string line3 =" 88   ";
	std::string line4 ="888888";
	
	for (int i = 0; i < 64; i++) {
		if (balancestring[i] == '0') {
			line1.append("  dP\"Yb ");
			line2.append(" dP   Yb");
			line3.append(" Yb   dP");
			line4.append("  YbodP ");
		}
		else if (balancestring[i] == '1') {
			line1.append("   .d");
			line2.append(" .d88");
			line3.append("   88");
			line4.append("   88");
		}
		else if (balancestring[i] == '2') {
			line1.append(" oP\"Yb.");
			line2.append(" \"' dP'");
			line3.append("   dP' ");
			line4.append(" .d8888");
		}
		else if (balancestring[i] == '3') {
			line1.append(" 88888");
			line2.append("   .dP");
			line3.append(" o `Yb");
			line4.append(" YbodP");
		}
		else if (balancestring[i] == '4') {
			line1.append("   dP88 ");
			line2.append("  dP 88 ");
			line3.append(" d888888");
			line4.append("     88");
		}
		else if (balancestring[i] == '5') {
			line1.append(" 888888");
			line2.append(" 88oo.\"");
			line3.append("    `8b");
			line4.append(" 8888P'");
		}
		else if (balancestring[i] == '6') {
			line1.append("   dP'  ");
			line2.append(" .d8'   ");
			line3.append(" 8P\"\"\"Yb");
			line4.append(" `YboodP");
		}
		else if (balancestring[i] == '7') {
			line1.append(" 888888P");
			line2.append("     dP ");
			line3.append("    dP  ");
			line4.append("   dP   ");
		}
		else if (balancestring[i] == '8') {
			line1.append(" .dP\"o.");
			line2.append(" `8b.d'");
			line3.append(" d'`Y8b");
			line4.append(" `bodP'");
		}
		else if (balancestring[i] == '9') {
			line1.append(" dP\"\"Yb");
			line2.append(" Ybood8");
			line3.append("   .8P'");
			line4.append("  .dP' ");
		}
		else if (balancestring[i] == '.') {
			line1.append("    ");
			line2.append("    ");
			line3.append(" .o.");
			line4.append(" `\"'");
		}
		else break;
	}

	for (int y = 52; y < 56; y++) {
		console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, 28, y);
		printf("                                                            ");
	}

	console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, 28, 52);
	printf(line1.c_str());
	console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, 28, 53);
	printf(line2.c_str());
	console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, 28, 54);
	printf(line3.c_str());
	console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, 28, 55);
	printf(line4.c_str());
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

void Cabinet::showSpinningReels(REEL_POSITIONS result) {
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