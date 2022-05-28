#include "OutcomeGenerator.h"

OutcomeGenerator::OutcomeGenerator() {
	rng = std::mt19937(time(0));
}

OUTCOME OutcomeGenerator::generateOutcome() {
	OUTCOME outcome;
	outcome.stake = 20;
	outcome.randomNumber = nextInt(80000);
	outcome.type = randomNumberToOutcomeType(outcome.randomNumber);
	if (outcome.type == THREE_BELLS) populate3BellsOutcome(&outcome);
	else if (outcome.type == THREE_SYMBOLS) populate3OfAKindOutcome(&outcome);
	else if (outcome.type == TWO_SYMBOLS) populate2OfAKindOutcome(&outcome);
	else populateLossOutcome(&outcome);
	return outcome;
}

void OutcomeGenerator::populate3BellsOutcome(OUTCOME* outcome) {
	outcome->prize = 500;
	outcome->reel1 = outcome->reel2 = outcome->reel3 = BELL;
}

void OutcomeGenerator::populate3OfAKindOutcome(OUTCOME* outcome) {
	outcome->prize = 100;
	do {
		outcome->reel1 = outcome->reel2 = outcome->reel3 = (SYMBOL)nextInt(6);
	} while (outcome->reel1 == BELL);
}

void OutcomeGenerator::populate2OfAKindOutcome(OUTCOME* outcome) {
	outcome->prize = 50;
	outcome->reel1 = outcome->reel2 = (SYMBOL)nextInt(6);
	do {
		outcome->reel3 = (SYMBOL)nextInt(6);
	} while (outcome->reel3 == outcome->reel1);
}

void OutcomeGenerator::populateLossOutcome(OUTCOME* outcome) {
	outcome->prize = 0;
	outcome->reel1 = (SYMBOL)nextInt(6);
	do {
		outcome->reel2 = (SYMBOL)nextInt(6);
	} while (outcome->reel2 == outcome->reel1);
	do {
		outcome->reel3 = (SYMBOL)nextInt(6);
	} while (outcome->reel3 == outcome->reel2 || outcome->reel3 == outcome->reel1);
}

OUTCOME_TYPE OutcomeGenerator::randomNumberToOutcomeType(unsigned int rn) {
	if (rn < 328) return THREE_BELLS;
	else if (rn < 3608) return THREE_SYMBOLS;
	else if (rn < 20008) return TWO_SYMBOLS;
	else return LOSE;
}

unsigned int OutcomeGenerator::nextInt(unsigned int bound) {
	unsigned int max = (4294967296 / bound) * bound;
	unsigned int result = 0;
	do {
		result = rng();
	} while (result > max);
	return result % bound;
}