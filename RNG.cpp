#include "RNG.h"

RNG::RNG() {
	rng = std::mt19937(time(0));
}

unsigned int RNG::nextInt(unsigned int bound) {
	unsigned int max = (4294967296 / bound) * bound;
	unsigned int result = 0;
	do {
		result = rng();
	} while (result > max);
	return result % bound;
}