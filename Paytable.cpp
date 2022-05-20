#include <iostream>
#include "Paytable.h"

OUTCOME Paytable::generateOutcome() {
	unsigned int rn = rng.nextInt(80000);
	if (rn < 328) return THREE_BELLS;
	else if (rn < 3608) return THREE_SYMBOLS;
	else if (rn < 20008) return TWO_SYMBOLS;
	else return LOSE;
}