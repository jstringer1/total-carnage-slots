#pragma once
#include "OutcomeGenerator.h"

class RTPTool {
public: 
	RTPTool(char* outputFile, OutcomeGenerator *rng, unsigned int cycles);
	double runTest();
private:
	char* outputFile;
	OutcomeGenerator *rng;
	unsigned int cycles;
	std::string getSymbolName(SYMBOL symbol);
};