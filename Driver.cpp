#include "RNG.h"
#include "Console.h"
#include "ButtonPanel.h"
#include "Wallet.h"
#include "Cabinet.h"
#include <iostream>
#include <fstream>

std::string getSymbolName(SYMBOL symbol) {
	if (symbol == CHERRY) return std::string("CHERRY");
	else if (symbol == BELL) return std::string("BELL");
	else if (symbol == LEMMON) return std::string("LEMMON");
	else if (symbol == ORANGE) return std::string("ORANGE");
	else if (symbol == STAR) return std::string("STAR");
	return std::string("SEVEN");
}

unsigned int getPrize(REEL_POSITIONS reels) {
	if (reels.reel1 == BELL && reels.reel2 == BELL && reels.reel3 == BELL) return 500;
	else if (reels.reel1 == reels.reel2 && reels.reel1 == reels.reel3) return 100;
	else if (reels.reel1 == reels.reel2) return 50;
	return 0;
}

void runRtpTest(RNG rng, char* outfile) {
	std::ofstream output;
	output.open(outfile, std::ios_base::app);
	output << "REEL1, REEL2, REEL3, STAKE, PRIZE, TOTAL_STAKE, TOTAL_PRIZE, RUNNING_RTP\n";

	char buffer[1024];
	double totstake = 0;
	double totprize = 0;
	double rtp;
	unsigned int gamecycles = 1000000;
	for (int i = 0; i < gamecycles; i++) {
		REEL_POSITIONS reels = rng.generateReelPositions();
		unsigned int stake = 20;
		unsigned int prize = getPrize(reels);
		totstake += stake;
		totprize += prize;
		rtp = totprize / totstake;
		sprintf_s(buffer, 1024, "%s, %s, %s, %u, %u, %.6f, %.6f, %.6f\n",
			getSymbolName(reels.reel1).c_str(), getSymbolName(reels.reel2).c_str(), getSymbolName(reels.reel3).c_str(),
			stake, prize, totstake, totprize, rtp);
		output << buffer;
	}
	output.close();
	printf("OVERALL RTP AFTER %u GAMECYCLES IS %.6f\n", gamecycles, rtp);
}

void main(int argc, char* argv[]) {
	RNG rng = RNG();
	if (argc > 1) {
		runRtpTest(rng, argv[1]);
	} else {
		Wallet wallet = Wallet(10000);
		Console console = Console();
		Cabinet cabinet = Cabinet(&console, &wallet);
		while (wallet.getBalance() >= 20) {
			UserInput input = cabinet.getButtons()->acceptUserInput();
			if (input == EXIT) {
				return;
			} else if (input == SPIN) {
				wallet.takeCredit(20);
				REEL_POSITIONS result = rng.generateReelPositions();
				unsigned int prize = getPrize(result);
				wallet.giveCredit(prize);
				console.setColourAndPosition(COLOUR_BRIGHT_WHITE, COLOUR_BLACK, 50, 40);
				printf("%s | %s | %s\n", getSymbolName(result.reel1).c_str(), getSymbolName(result.reel2).c_str(), getSymbolName(result.reel3).c_str());
			}
		}
	}
}