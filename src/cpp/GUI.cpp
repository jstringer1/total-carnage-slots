#include "GUI.h"
#include "Symbols.h"
#include "resource.h"

GUI::GUI(Console* console, Wallet* wallet, SoundController *sound) {
	GUI::console = console;
	GUI::wallet = wallet;
	GUI::sound = sound;
	GUI::buttons = new ButtonPanel(console);
	GUI::balance = new BalancePanel(console, COLOUR_PURPLE, COLOUR_BLACK, 28, 52);
	console->setColourAndPosition(COLOUR_BLACK, COLOUR_GREY,0,0);
	for (int i = 0; i < 120; i++) printf("                                                                                                                                                                                                                                                                       \n");
	console->setColourAndPosition(COLOUR_BLACK, COLOUR_BLACK, 0, 0);
	for (int i = 0; i < 57; i++) printf("                                                                                                     \n");
	onCreditChangeEvent();
	wallet->registerListener(this);

	console->printResource(IDR_TITLE, COLOUR_PURPLE, COLOUR_BLACK, 0);
	console->printResource(IDR_REELS, COLOUR_GREEN, COLOUR_BLACK, 19);
	console->printResource(IDR_WINLINE, COLOUR_LIGHT_RED, COLOUR_BLACK, 34);

	GUI::reel1 = new ReelPanel(console, 13, 3);
	GUI::reel2 = new ReelPanel(console, 40, 0);
	GUI::reel3 = new ReelPanel(console, 67, 5);

	reel1->drawCurrentFrame(COLOUR_BLACK);
	reel2->drawCurrentFrame(COLOUR_BLACK);
	reel3->drawCurrentFrame(COLOUR_BLACK);
}

GUI::~GUI() {
	delete buttons;
	delete balance;
	delete reel1;
	delete reel2;
	delete reel3;
	wallet->unregisterListener(this);
	console = NULL;
	wallet = NULL;
	buttons = NULL;
	reel1 = reel2 = reel3 = NULL;
}

ButtonPanel* GUI::getButtons() {
	return buttons;
}

void GUI::onCreditChangeEvent() {
	double balance = wallet->getBalance() / 100.0;
	char balancestring[64];
	sprintf_s(balancestring, 64, "£%.2f", balance);

	for (int y = 52; y < 56; y++) {
		console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, 28, y);
		printf("                                                            ");
	}
	GUI::balance->printBalance(std::string(balancestring));
}

void GUI::showOutcome(OUTCOME result) {
	int frame = 0;
	bool stopped[3] = {false, false, false};
	int frameDuration = 30;
	while (!stopped[2]) {
		if (!stopped[0]) stopped[0] = reel1->incrementFrame((frame++ > 50), result.reel1);
		if (!stopped[1]) stopped[1] = reel2->incrementFrame(stopped[0], result.reel2);
		if (!stopped[2]) stopped[2] = reel3->incrementFrame(stopped[1], result.reel3);
		reel1->drawCurrentFrame(COLOUR_BLACK);
		reel2->drawCurrentFrame(COLOUR_BLACK);
		reel3->drawCurrentFrame(COLOUR_BLACK);
		Sleep(frameDuration);
	}

	if (result.type == THREE_BELLS) sound->playILoveIt();
	else if (result.type == THREE_SYMBOLS) sound->playBigPrizes();
	else if (result.type == TWO_SYMBOLS) sound->playBigMoney();
	else sound->playTotalCarnage();

	for (int i = 0; i < 5; i++) {
		if (result.reel1 == result.reel2) {
			reel1->drawCurrentFrame(COLOUR_WHITE);
			reel2->drawCurrentFrame(COLOUR_WHITE);
		}
		if (result.reel1 == result.reel3) reel3->drawCurrentFrame(COLOUR_WHITE);
		Sleep(frameDuration*3);
		reel1->drawCurrentFrame(COLOUR_BLACK);
		reel2->drawCurrentFrame(COLOUR_BLACK);
		reel3->drawCurrentFrame(COLOUR_BLACK);
		Sleep(frameDuration*3);
	}
}