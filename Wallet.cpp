#include "Wallet.h"

Wallet::Wallet(unsigned int balance) {
	Wallet::balance = balance;
}
void Wallet::takeCredit(unsigned int amount) {
	balance -= amount;
	notfiyListeners();
}

void Wallet::giveCredit(unsigned int amount) {
	balance += amount;
	notfiyListeners();
}

unsigned int Wallet::getBalance() {
	return balance;
}

void Wallet::registerListener(CreditChangeListener* listener) {
	listeners.insert(listener);
}

void Wallet::unregisterListener(CreditChangeListener* listener) {
	listeners.erase(listener);
}

void Wallet::notfiyListeners() {
	std::set<CreditChangeListener*>::iterator it;
	for (it = listeners.begin(); it != listeners.end(); it++) 
		(*it)->onCreditChangeEvent();
}