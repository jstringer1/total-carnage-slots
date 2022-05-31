# Total Carnage Slots

A simple slots game where the GUI is drawn in a console window.

![screenshot](https://bitbucket.ingg.com/users/john.stringer/repos/superslots/raw/screenshot/Screenshot.png?at=refs%2Fheads%2Fmaster)

### THEORETICAL RETURN TO PLAYER

The game has a theoretical RTP of 82%. Game outcome is determined by random numbers drawn in the range 0(inclusive) and 100000(exclusive). The games "outcome type" is then calculated from the random number based on the table below:

| Random Min | Random Max | OUTCOME TYPE | COUNT | Stake | Prize | Total Stake | Total Prize |
|------------|------------|--------------|-------|-------|-------|-------------|-------------|
|          0 |        327 | 3 BELLS      |   328 |    20 |   500 |        6560 |      164000 |
|        328 |       3607 | 3 OF A KIND  |  3280 |    20 |   100 |       65600 |      328000 |
|       3608 |      26567 | 2 OF A KIND  | 22960 |    20 |    50 |      459200 |     1148000 |
|      26568 |      99999 | LOSE         | 73432 |    20 |     0 |     1468640 |           0 |

Given that all 100k outcomes should be equally likely, if a player was to play 100k spins, theoretically they'd hit all 100k possibilities giving a total prize, total stake and theoretical RTP of:

| TOT TOT STAKE                             | TOT TOT PRIZE                       | THORETICAL RTP           |
|-------------------------------------------|-------------------------------------|--------------------------|
| 6560 + 65600 + 459200 + 1468640 = 2000000 | 164000 + 328000 + 1148000 = 1640000 | 1640000 / 2000000 = 0.82 |

You can test the actual RTP over 100k cycles by adding a command line argument representing a relative file path to a location to output CSV results to for the 100k cycles.

### Known Bugs

* Resizing the console window while the game is running doesn't work.