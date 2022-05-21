#include "Console.h"
#include "Symbols.h"

void printCherry(Console* console, int x, int y) {
    console->setColourAndPosition(COLOUR_GREEN, COLOUR_BLACK, x, y);
    printf("     |\\        ");
    console->setPosition(x, y+1);
    printf("    |   \\      ");
    console->setPosition(x, y+2);
    printf("    |    \\     ");
    console->setColourAndPosition(COLOUR_RED, COLOUR_BLACK, x, y+3);
    printf(".coovaa,   ");
    console->setColourAndPosition(COLOUR_GREEN, COLOUR_BLACK, x+11, y+3);
    printf("\\   ");
    console->setColourAndPosition(COLOUR_RED, COLOUR_BLACK, x, y+4);
    printf("88888888.coovaa,");
    console->setPosition(x, y+5);
    printf("8888888800000000");
    console->setPosition(x, y+6);
    printf("`YbbbdP'00000000");
    console->setPosition(x, y+7);
    printf("        `YbbbdP'\n");
}

void printBell(Console* console, int x, int y) {
    console->setColourAndPosition(COLOUR_ORANGE, COLOUR_BLACK, x, y);
    printf("                ");
    console->setPosition(x, y + 1);
    printf("      .ca.      ");
    console->setPosition(x, y + 2);
    printf("     (*88*)     ");
    console->setPosition(x, y + 3);
    printf("    .888888.    ");
    console->setPosition(x, y + 4);
    printf("   (88888888)   ");
    console->setPosition(x, y + 5);
    printf("  .888****888.  ");
    console->setPosition(x, y + 6);
    printf(" (8*__,");
    console->setColourAndPosition(COLOUR_YELLOW, COLOUR_BLACK, x+7, y+6);
    printf("()");
    console->setColourAndPosition(COLOUR_ORANGE, COLOUR_BLACK, x+9, y+6);
    printf(",__*8) ");
    console->setPosition(x, y + 7);
    printf("                \n");
}

void printLemmon(Console *console, int x, int y) {
    console->setColourAndPosition(COLOUR_YELLOW, COLOUR_BLACK,x,y);
    printf("       ...oa.   ");
    console->setPosition(x, y + 1);
    printf("      8.cao88p  ");
    console->setPosition(x, y + 2);
    printf("    8888888888  ");
    console->setPosition(x, y + 3);
    printf("   88888888888  ");
    console->setPosition(x, y + 4);
    printf("   88888888888  ");
    console->setPosition(x, y + 5);
    printf("  .888888888`   ");
    console->setPosition(x, y + 6);
    printf("  888888`       ");
    console->setPosition(x, y + 7);
    printf("   `            ");
}

void printOrange(Console *console, int x, int y) {
    console->setColourAndPosition(COLOUR_ORANGE, COLOUR_BLACK, x, y);
    printf("                ");
    console->setPosition(x, y + 1);
    printf("    .cooaa,     ");
    console->setPosition(x, y + 2);
    printf("   '8888");
    console->setColourAndPosition(COLOUR_GREEN, COLOUR_BLACK, x+8,y+2);
    printf(".8.");
    console->setColourAndPosition(COLOUR_ORANGE, COLOUR_BLACK, x+11, y+2);
    printf("8,   ");
    console->setPosition(x, y + 3);
    printf("  '888888");
    console->setColourAndPosition(COLOUR_GREEN, COLOUR_BLACK,x+9, y+3);
    printf("`");
    console->setColourAndPosition(COLOUR_ORANGE, COLOUR_BLACK,x+10,y+3);
    printf("888,  ");
    console->setPosition(x, y + 4);
    printf(" 1888888888888; ");
    console->setPosition(x, y + 5);
    printf("  888888888888  ");
    console->setPosition(x, y + 6);
    printf("   8888888888   ");
    console->setPosition(x, y + 7);
    printf("    `YbbbdP'    ");
}

void printStar(Console *console, int x, int y) {
    console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK,x,y);
    printf("       n        ");
    console->setPosition(x, y + 1);
    printf("      /88\\     ");
    console->setPosition(x, y + 2);
    printf("  ___/8888\\___");
    console->setPosition(x, y + 3);
    printf("  `888888888888` ");
    console->setPosition(x, y + 4);
    printf("   \\888888888/  ");
    console->setPosition(x, y + 5);
    printf("   /888/^8888\\   ");
    console->setPosition(x, y + 6);
    printf("  /+./    \\.+\\   ");
    console->setPosition(x, y + 7);
    printf("  :`        `;    ");
}

void printSeven(Console *console, int x, int y) {
    console->setColourAndPosition(COLOUR_BLUE, COLOUR_BLACK,x,y);
    printf(".==============.");
    console->setPosition(x, y + 1);
    printf("`===========  =`");
    console->setPosition(x, y + 2);
    printf("           # #` ");
    console->setPosition(x, y + 3);
    printf("          # #`  ");
    console->setPosition(x, y + 4);
    printf("         # #`   ");
    console->setPosition(x, y + 5);
    printf("        # #`    ");
    console->setPosition(x, y + 6);
    printf("       # #`     ");
    console->setPosition(x, y + 7);
    printf("      ###`      ");
}

void printSymbol(Console* console, SYMBOL symbol, int x, int y) {
    if (symbol == CHERRY) printCherry(console, x, y);
    else if (symbol == BELL) printBell(console, x, y);
    else if (symbol == LEMMON) printLemmon(console, x, y);
    else if (symbol == ORANGE) printOrange(console, x, y);
    else if (symbol == STAR) printStar(console, x, y);
    else if (symbol == SEVEN) printSeven(console, x, y);
}