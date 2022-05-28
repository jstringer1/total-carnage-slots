#include "OutcomeGenerator.h"
#include "Console.h"
#include "ButtonPanel.h"
#include "Wallet.h"
#include "Cabinet.h"
#include <iostream>
#include <fstream>
#include "SoundEffect.h"

std::string getSymbolName(SYMBOL symbol) {
	if (symbol == CHERRY) return std::string("CHERRY");
	else if (symbol == BELL) return std::string("BELL");
	else if (symbol == LEMMON) return std::string("LEMMON");
	else if (symbol == ORANGE) return std::string("ORANGE");
	else if (symbol == STAR) return std::string("STAR");
	return std::string("SEVEN");
}

void runRtpTest(OutcomeGenerator rng, char* outfile) {
	std::ofstream output;
	output.open(outfile, std::ios_base::app);
	output << "REEL1, REEL2, REEL3, STAKE, PRIZE, TOTAL_STAKE, TOTAL_PRIZE, RUNNING_RTP\n";

	char buffer[1024];
	double totstake = 0;
	double totprize = 0;
	double rtp;
	unsigned int gamecycles = 1000000;
	for (int i = 0; i < gamecycles; i++) {
		OUTCOME outcome = rng.generateOutcome();
		totstake += outcome.stake;
		totprize += outcome.prize;
		rtp = totprize / totstake;
		sprintf_s(buffer, 1024, "%s, %s, %s, %u, %u, %.6f, %.6f, %.6f\n",
			getSymbolName(outcome.reel1).c_str(), getSymbolName(outcome.reel2).c_str(), getSymbolName(outcome.reel3).c_str(),
			outcome.stake, outcome.prize, totstake, totprize, rtp);
		output << buffer;
	}
	output.close();
	printf("OVERALL RTP AFTER %u GAMECYCLES IS %.6f\n", gamecycles, rtp);
}

void main(int argc, char* argv[]) {
	OutcomeGenerator rng = OutcomeGenerator();
	if (argc > 1) {
		runRtpTest(rng, argv[1]);
	} else {
		SoundController sound = SoundController();
		sound.playILoveIt();
		Wallet wallet = Wallet(10000);
		Console console = Console();
		Cabinet cabinet = Cabinet(&console, &wallet, &sound);
		while (wallet.getBalance() >= 20) {
			UserInput input = cabinet.getButtons()->acceptUserInput();
			if (input == EXIT) {
				return;
			} else if (input == SPIN) {
				sound.playGoodLuck();
				wallet.takeCredit(20);
				OUTCOME result = rng.generateOutcome();
				cabinet.showSpinningReels(result);
				wallet.giveCredit(result.prize);
			}
		}
	}
}