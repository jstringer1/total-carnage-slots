#pragma once

#include <ctime>
#include <random>

enum SYMBOL {
	CHERRY,
	BELL,
	LEMMON,
	ORANGE,
	STAR,
	SEVEN
};

enum OUTCOME_TYPE {
	LOSE,
	TWO_SYMBOLS,
	THREE_SYMBOLS,
	THREE_BELLS
};

struct OUTCOME {
	unsigned int randomNumber;
	OUTCOME_TYPE type;
	SYMBOL reel1;
	SYMBOL reel2;
	SYMBOL reel3;
	unsigned int stake;
	unsigned int prize;
};

class OutcomeGenerator {
public:
	OutcomeGenerator();
	OUTCOME generateOutcome();
private:
	std::mt19937 rng;
	void populate3BellsOutcome(OUTCOME* outcome);
	void populate3OfAKindOutcome(OUTCOME* outcome);
	void populate2OfAKindOutcome(OUTCOME* outcome);
	void populateLossOutcome(OUTCOME* outcome);
	OUTCOME_TYPE randomNumberToOutcomeType(unsigned int randomNumber);
	unsigned int nextInt(unsigned int exclusiveUpperBound);
};