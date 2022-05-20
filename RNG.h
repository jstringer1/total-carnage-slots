#pragma once

#include <ctime>
#include <random>

class RNG {
public:
	RNG();
	unsigned int nextInt(unsigned int exclusiveUpperBound);
private:
	std::mt19937 rng;
};