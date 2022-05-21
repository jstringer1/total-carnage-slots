#pragma once
#include <set>

class CreditChangeListener {
public:
	virtual void onCreditChangeEvent() = 0;
};

class Wallet {
public:
	Wallet(unsigned int balance);
	void takeCredit(unsigned int amount);
	void giveCredit(unsigned int amount);
	unsigned int getBalance();
	void registerListener(CreditChangeListener* listener);
	void unregisterListener(CreditChangeListener* listener);
private:
	unsigned int balance;
	std::set<CreditChangeListener*> listeners;
	void notfiyListeners();
};