#include "OutcomeGenerator.h"
#include "Console.h"
#include "ButtonPanel.h"
#include "Wallet.h"
#include "GUI.h"
#include <iostream>
#include <fstream>
#include "SoundEffect.h"
#include "RTPTool.h"

void main(int argc, char* argv[]) {
	OutcomeGenerator rng = OutcomeGenerator();
	if (argc > 1) {
		unsigned int cycles = 100000;
		RTPTool rtpTool = RTPTool(argv[1], &rng, cycles);
		double rtp = rtpTool.runTest();
		printf("OVERALL RTP AFTER %u GAMECYCLES IS %.6f\n", cycles, rtp);
	} else {
		SoundController sound = SoundController();
		sound.playILoveIt();
		Wallet wallet = Wallet(10000);
		Console console;
		GUI gui = GUI(&console, &wallet, &sound);
		while (wallet.getBalance() >= 20) {
			UserInput input = gui.getButtons()->acceptUserInput();
			if (input == EXIT) {
				return;
			} else if (input == SPIN) {
				sound.playGoodLuck();
				wallet.takeCredit(20);
				OUTCOME result = rng.generateOutcome();
				gui.showOutcome(result);
				wallet.giveCredit(result.prize);
			}
		}
	}
}