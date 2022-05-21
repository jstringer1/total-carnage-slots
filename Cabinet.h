#pragma once
#include "Console.h"
#include "ButtonPanel.h"
#include "Wallet.h"
#include "RNG.h"

class Cabinet : CreditChangeListener {
public:
	Cabinet(Console* console, Wallet* wallet);
	~Cabinet();
	ButtonPanel* getButtons();
	void showSpinningReels(REEL_POSITIONS result);
	virtual void onCreditChangeEvent() override;
private:
	Console* console;
	Wallet* wallet;
	ButtonPanel* buttons;
};