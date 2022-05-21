#pragma once

#include <ctime>
#include <random>

enum OUTCOME {
	LOSE,
	TWO_SYMBOLS,
	THREE_SYMBOLS,
	THREE_BELLS
};

enum SYMBOL {
	CHERRY,
	BELL,
	LEMMON,
	ORANGE,
	STAR,
	SEVEN
};

struct REEL_POSITIONS{
	SYMBOL reel1;
	SYMBOL reel2;
	SYMBOL reel3;
};

class RNG {
public:
	RNG();
	REEL_POSITIONS generateReelPositions();
	OUTCOME generateOutcome();
	unsigned int nextInt(unsigned int exclusiveUpperBound);
private:
	std::mt19937 rng;
};

