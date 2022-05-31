# Total Carnage Slots

A simple slots game where the GUI is drawn in a console window.

### THEORETICAL RETURN TO PLAYER

The game has a theoretical RTP of 82%. Game outcome is determined by random numbers drawn in the range 0(inclusive) and 80000(exclusive). The games "outcome type" is then calculated from the random number based on the table below:

| Random Min | Random Max | OUTCOME TYPE | COUNT | Stake | Prize | Total Stake | Total Prize |
|------------|------------|--------------|-------|-------|-------|-------------|-------------|
|          0 |        327 | 3 BELLS      |   328 |    20 |   500 |        6560 |      164000 |
|        328 |       3607 | 3 OF A KIND  |  3280 |    20 |   100 |       65600 |      328000 |
|       3608 |      20007 | 2 OF A KIND  | 16500 |    20 |    50 |      328000 |      820000 |
|      20008 |      79999 | LOSE         | 59992 |    20 |     0 |     1199840 |           0 |

Given that all 80k outcomes should be equally likely, if a player was to play 80k spins, theoretically they'd hit all 80k possibilities giving a total prize, total stake and theoretical RTP of:

TOT TOT STAKE  = 6560 + 65600 + 328000 + 1199840 = 1600000
TOT TOT PRIZE  = 164000 + 328000 + 820000        = 1312000
THORETICAL RTP = 1312000 / 1600000               =    0.82

You can test the actual RTP over 100k cycles by adding a command line argument representing a relative file path to a location to output CSV results to for the 100k cycles.

### Known Bugs

* Resizing the console window while the game is running doesn't work.