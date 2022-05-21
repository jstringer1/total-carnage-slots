#include "RNG.h"

RNG::RNG() {
	rng = std::mt19937(time(0));
}

REEL_POSITIONS RNG::generateReelPositions() {
	OUTCOME outcome = generateOutcome();
	REEL_POSITIONS result = REEL_POSITIONS();
	if (outcome == THREE_BELLS) {
		result.reel1 = result.reel2 = result.reel3 = BELL;
	}
	else if (outcome == THREE_SYMBOLS) {
		do {
			result.reel1 = result.reel2 = result.reel3 = (SYMBOL)nextInt(6);
		} while (result.reel1 == BELL);
	}
	else if (outcome == TWO_SYMBOLS) {
		result.reel1 = result.reel2 = (SYMBOL)nextInt(6);
		do {
			result.reel3 = (SYMBOL)nextInt(6);
		} while (result.reel3 == result.reel1);
	}
	else {
		result.reel1 = (SYMBOL)nextInt(6);
		do {
			result.reel2 = (SYMBOL)nextInt(6);
		} while (result.reel2 == result.reel1);
		do {
			result.reel3 = (SYMBOL)nextInt(6);
		} while (result.reel3 == result.reel2 || result.reel3 == result.reel1);
	}
	return result;
}

OUTCOME RNG::generateOutcome() {
	unsigned int rn = nextInt(80000);
	if (rn < 328) return THREE_BELLS;
	else if (rn < 3608) return THREE_SYMBOLS;
	else if (rn < 20008) return TWO_SYMBOLS;
	else return LOSE;
}

unsigned int RNG::nextInt(unsigned int bound) {
	unsigned int max = (4294967296 / bound) * bound;
	unsigned int result = 0;
	do {
		result = rng();
	} while (result > max);
	return result % bound;
}