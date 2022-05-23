#include "Console.h"
#include "Symbols.h"

void printTitle(Console* console, int x, int y) {
    console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, x+10, y);
    printf("________   ______  ________   ______   __");
    console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, x + 10, y+1);
    printf("|        \ /      \|        \ /      \ |  \\");
    console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, x + 10, y+2);
    printf("\\$$$$$$$$ | $$$$$$\\\\$$$$$$$$ | $$$$$$\ | $$");
    console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, x + 10, y+3);
    printf("   | $$   | $$  | $$  | $$   | $$__| $$| $$");
    console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, x + 10, y+4);
    printf("   | $$   | $$  | $$  | $$   | $$    $$| $$");
    console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, x + 10, y+5);
    printf("   | $$   | $$  | $$  | $$   | $$$$$$$$| $$");
    console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, x + 10, y+6);
    printf("   | $$   | $$__/ $$  | $$   | $$  | $$| $$_____");
    console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, x + 10, y+7);
    printf("   | $$    \\$$    $$  | $$   | $$  | $$| $$     \\");
    console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, x + 10, y+8);
    printf("    \\$$     \\$$$$$$    \\$$    \\$$   \\$$ \\$$$$$$$$");

    console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, x, y+9);
    printf("  ______    ______   _______   __    __   ______    ______   ________");
    console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, x, y + 10);
    printf(" /      \\  /      \\ |       \\ |  \\  |  \\ /      \\  /      \\ |        \\");
    console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, x, y + 11);
    printf("|  $$$$$$\\|  $$$$$$\\| $$$$$$$\\| $$\\ | $$|  $$$$$$\\|  $$$$$$\\| $$$$$$$$");
    console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, x, y + 12);
    printf("| $$   \\$$| $$__| $$| $$__| $$| $$$\\| $$| $$__| $$| $$ __\\$$| $$__ ");
    console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, x, y + 13);
    printf("| $$      | $$    $$| $$    $$| $$$$\\ $$| $$    $$| $$|    \\| $$  \\");
    console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, x, y + 14);
    printf("| $$   __ | $$$$$$$$| $$$$$$$\\| $$\\$$ $$| $$$$$$$$| $$ \\$$$$| $$$$$");
    console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, x, y + 15);
    printf("| $$__/  \\| $$  | $$| $$  | $$| $$ \\$$$$| $$  | $$| $$__| $$| $$_____ ");
    console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, x, y + 16);
    printf(" \\$$    $$| $$  | $$| $$  | $$| $$  \\$$$| $$  | $$ \\$$    $$| $$     \\");
    console->setColourAndPosition(COLOUR_PURPLE, COLOUR_BLACK, x, y + 17);
    printf("  \\$$$$$$  \\$$   \\$$ \\$$   \\$$ \\$$   \\$$ \\$$   \\$$  \\$$$$$$  \\$$$$$$$$");
}

void printCherry(Console* console, int x, int y, COLOUR background) {
    console->setColourAndPosition(COLOUR_GREEN, background, x, y);
    printf("                ");
    if (y >= 48) return;
    console->setPosition(x, y+1);
    printf("     |\\         ");
    if (y >= 47) return;
    console->setPosition(x, y+2);
    printf("    |   \\       ");
    if (y >= 46) return;
    console->setPosition(x, y+3);
    printf("    |    \\      ");
    if (y >= 45) return;
    console->setColourAndPosition(COLOUR_RED, background, x, y+4);
    printf(".coovaa,   ");
    console->setColourAndPosition(COLOUR_GREEN, background, x+11, y+4);
    printf("\\    ");
    if (y >= 44) return;
    console->setColourAndPosition(COLOUR_RED, background, x, y+5);
    printf("88888888.coovaa,");
    if (y >= 43) return;
    console->setPosition(x, y+6);
    printf("8888888800000000");
    if (y >= 42) return;
    console->setPosition(x, y+7);
    printf("`YbbbdP'00000000");
    if (y >= 41) return;
    console->setPosition(x, y+8);
    printf("        `YbbbdP'");
    if (y >= 40) return;
    console->setPosition(x, y + 9);
    printf("                ");
}

void printBell(Console* console, int x, int y, COLOUR background) {
    console->setColourAndPosition(COLOUR_ORANGE, background, x, y);
    printf("                ");
    if (y >= 48) return;
    console->setPosition(x, y + 1);
    printf("                ");
    if (y >= 47) return;
    console->setPosition(x, y + 2);
    printf("      .ca.      ");
    if (y >= 46) return;
    console->setPosition(x, y + 3);
    printf("     (*88*)     ");
    if (y >= 45) return;
    console->setPosition(x, y + 4);
    printf("    .888888.    ");
    if (y >= 44) return;
    console->setPosition(x, y + 5);
    printf("   (88888888)   ");
    if (y >= 43) return;
    console->setPosition(x, y + 6);
    printf("  .888****888.  ");
    if (y >= 42) return;
    console->setPosition(x, y + 7);
    printf(" (8*__,");
    console->setColourAndPosition(COLOUR_YELLOW, background, x+7, y+7);
    printf("()");
    console->setColourAndPosition(COLOUR_ORANGE, background, x+9, y+7);
    printf(",__*8) ");
    if (y >= 41) return;
    console->setPosition(x, y + 8);
    printf("                ");
    if (y >= 40) return;
    console->setPosition(x, y + 9);
    printf("                ");
}

void printLemmon(Console *console, int x, int y, COLOUR background) {
    console->setColourAndPosition(COLOUR_YELLOW, background,x,y);
    printf("                ");
    if (y >= 48) return;
    console->setPosition(x, y + 1);
    printf("       .ooaa.   ");
    if (y >= 47) return;
    console->setPosition(x, y + 2);
    printf("      8ocao88p  ");
    if (y >= 46) return;
    console->setPosition(x, y + 3);
    printf("    8888888888  ");
    if (y >= 45) return;
    console->setPosition(x, y + 4);
    printf("   88888888888  ");
    if (y >= 44) return;
    console->setPosition(x, y + 5);
    printf("   88888888888  ");
    if (y >= 43) return;
    console->setPosition(x, y + 6);
    printf("  .888888888`   ");
    if (y >= 42) return;
    console->setPosition(x, y + 7);
    printf("  888888`       ");
    if (y >= 41) return;
    console->setPosition(x, y + 8);
    printf("   `            ");
    if (y >= 40) return;
    console->setPosition(x, y + 9);
    printf("                ");
}

void printOrange(Console *console, int x, int y, COLOUR background) {
    console->setColourAndPosition(COLOUR_ORANGE, background, x, y);
    printf("                ");
    if (y >= 48) return;
    console->setPosition(x, y + 1);
    printf("                ");
    if (y >= 47) return;
    console->setPosition(x, y + 2);
    printf("    .cooaa,     ");
    if (y >= 46) return;
    console->setPosition(x, y + 3);
    printf("   '8888");
    console->setColourAndPosition(COLOUR_GREEN, background, x+8,y+3);
    printf(".8.");
    console->setColourAndPosition(COLOUR_ORANGE, background, x+11, y+3);
    printf("8,   ");
    if (y >= 45) return;
    console->setPosition(x, y + 4);
    printf("  '888888");
    console->setColourAndPosition(COLOUR_GREEN, background,x+9, y+4);
    printf("`");
    console->setColourAndPosition(COLOUR_ORANGE, background,x+10,y+4);
    printf("888,  ");
    if (y >= 44) return;
    console->setPosition(x, y + 5);
    printf(" 1888888888888; ");
    if (y >= 43) return;
    console->setPosition(x, y + 6);
    printf("  888888888888  ");
    if (y >= 42) return;
    console->setPosition(x, y + 7);
    printf("   8888888888   ");
    if (y >= 41) return;
    console->setPosition(x, y + 8);
    printf("    `YbbbdP'    ");
    if (y >= 40) return;
    console->setPosition(x, y + 9);
    printf("                ");
}

void printStar(Console *console, int x, int y, COLOUR background) {
    console->setColourAndPosition(COLOUR_PURPLE, background,x,y);
    printf("                ");
    if (y >= 48) return;
    console->setPosition(x, y + 1);
    printf("        .       ");
    if (y >= 47) return;
    console->setPosition(x, y + 2);
    printf("       ,O,      ");
    if (y >= 46) return;
    console->setPosition(x, y + 3);
    printf("      ,OOO,     ");
    if (y >= 45) return;
    console->setPosition(x, y + 4);
    printf(" 'ooooOOOOOoooo'");
    if (y >= 44) return;
    console->setPosition(x, y + 5);
    printf("  `oOOOOOOOOOo` ");
    if (y >= 43) return;
    console->setPosition(x, y + 6);
    printf("   `OOOO.OOOO`  ");
    if (y >= 42) return;
    console->setPosition(x, y + 7);
    printf("   OOO     OOO  ");
    if (y >= 41) return;
    console->setPosition(x, y + 8);
    printf("  O'         'O ");
    if (y >= 40) return;
    console->setPosition(x, y + 9);
    printf("                ");
}

void printSeven(Console *console, int x, int y, COLOUR background) {
    console->setColourAndPosition(COLOUR_BLUE, background,x,y);
    printf("                ");
    if (y >= 48) return;
    console->setPosition(x, y + 1);
    printf(".==============.");
    if (y >= 47) return;
    console->setPosition(x, y + 2);
    printf("`===========  =`");
    if (y >= 46) return;
    console->setPosition(x, y + 3);
    printf("           # #` ");
    if (y >= 45) return;
    console->setPosition(x, y + 4);
    printf("          # #`  ");
    if (y >= 44) return;
    console->setPosition(x, y + 5);
    printf("         # #`   ");
    if (y >= 43) return;
    console->setPosition(x, y + 6);
    printf("        # #`    ");
    if (y >= 42) return;
    console->setPosition(x, y + 7);
    printf("       # #`     ");
    if (y >= 41) return;
    console->setPosition(x, y + 8);
    printf("      ###`      ");
    if (y >= 40) return;
    console->setPosition(x, y + 9);
    printf("                ");
}

void printSymbol(Console* console, SYMBOL symbol, int x, int y, COLOUR background) {
    if (symbol == CHERRY) printCherry(console, x, y, background);
    else if (symbol == BELL) printBell(console, x, y, background);
    else if (symbol == LEMMON) printLemmon(console, x, y, background);
    else if (symbol == ORANGE) printOrange(console, x, y, background);
    else if (symbol == STAR) printStar(console, x, y, background);
    else if (symbol == SEVEN) printSeven(console, x, y, background);
}