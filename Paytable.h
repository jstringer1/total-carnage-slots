#pragma once
#include "RNG.h"

enum OUTCOME {
	LOSE,
	TWO_SYMBOLS,
	THREE_SYMBOLS,
	THREE_BELLS
};

class Paytable {
public:
	OUTCOME generateOutcome();
private:
	RNG rng;
};