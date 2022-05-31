#pragma once
#include "Console.h"
#include "ButtonPanel.h"
#include "BalancePanel.h"
#include "Wallet.h"
#include "OutcomeGenerator.h"
#include "SoundEffect.h"
#include "ReelPanel.h"

class GUI : CreditChangeListener {
public:
	GUI(Console* console, Wallet* wallet, SoundController* sound);
	~GUI();
	ButtonPanel* getButtons();
	void showOutcome(OUTCOME result);
	virtual void onCreditChangeEvent() override;
private:
	Console* console;
	Wallet* wallet;
	SoundController* sound;
	ButtonPanel* buttons;
	BalancePanel* balance;
	ReelPanel* reel1;
	ReelPanel* reel2;
	ReelPanel* reel3;
};