#pragma once
#include "Console.h"
#include "ButtonPanel.h"
#include "BalancePanel.h"
#include "Wallet.h"
#include "OutcomeGenerator.h"
#include "SoundEffect.h"

class Cabinet : CreditChangeListener {
public:
	Cabinet(Console* console, Wallet* wallet, SoundController* sound);
	~Cabinet();
	ButtonPanel* getButtons();
	void showSpinningReels(OUTCOME result);
	virtual void onCreditChangeEvent() override;
private:
	Console* console;
	Wallet* wallet;
	SoundController* sound;
	ButtonPanel* buttons;
	BalancePanel* balance;
};