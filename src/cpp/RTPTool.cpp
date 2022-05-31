#include "RTPTool.h"
#include <iostream>
#include <fstream>

RTPTool::RTPTool(char* outputFile, OutcomeGenerator* rng, unsigned int cycles) {
	RTPTool::outputFile = outputFile;
	RTPTool::rng = rng;
	RTPTool::cycles = cycles;
}

double RTPTool::runTest() {
	std::ofstream output;
	output.open(outputFile, std::ios_base::app);
	output << "RANDOM_NUMBER, REEL1, REEL2, REEL3, STAKE, PRIZE, TOTAL_STAKE, TOTAL_PRIZE, RUNNING_RTP\n";

	char buffer[1024];
	unsigned long totstake = 0;
	unsigned long totprize = 0;
	double rtp = 0;
	for (int i = 0; i < cycles; i++) {
		OUTCOME outcome = rng->generateOutcome();
		totstake += outcome.stake;
		totprize += outcome.prize;
		rtp = (double)totprize / (double)totstake;
		sprintf_s(buffer, 1024, "%u, %s, %s, %s, %u, %u, %.6f, %.6f, %.6f\n",
			outcome.randomNumber, getSymbolName(outcome.reel1).c_str(), getSymbolName(outcome.reel2).c_str(), getSymbolName(outcome.reel3).c_str(),
			outcome.stake, outcome.prize, totstake, totprize, rtp);
		output << buffer;
	}
	output.close();
	return rtp;
}

std::string RTPTool::getSymbolName(SYMBOL symbol) {
	if (symbol == CHERRY) return std::string("CHERRY");
	else if (symbol == BELL) return std::string("BELL");
	else if (symbol == LEMMON) return std::string("LEMMON");
	else if (symbol == ORANGE) return std::string("ORANGE");
	else if (symbol == STAR) return std::string("STAR");
	return std::string("SEVEN");
}