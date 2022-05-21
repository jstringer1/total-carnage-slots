#pragma once
#include "Console.h"
#include "ButtonPanel.h"
#include "Wallet.h"

class Cabinet : CreditChangeListener {
public:
	Cabinet(Console* console, Wallet* wallet);
	~Cabinet();
	ButtonPanel* getButtons();
	virtual void onCreditChangeEvent() override;
private:
	Console* console;
	Wallet* wallet;
	ButtonPanel* buttons;
};