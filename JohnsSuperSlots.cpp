#include <iostream>
#include <windows.h>

HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

enum COLOUR {
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    AQUA = 3,
    RED = 4,
    PURPLE = 5,
    ORANGE = 6,
    WHITE = 7,
    GREY = 8,
    LIGHT_BLUE = 9,
    LIGHT_GREEN = 10,
    LIGHT_AQUA = 11,
    LIGHT_RED = 12,
    LIGHT_PURPLE = 13,
    YELLOW = 14,
    BRIGHT_WHITE = 15
};

void setColour(COLOUR foreground, COLOUR background) {
    SetConsoleTextAttribute(out, foreground +(16* background));
}

void cherry() {
    setColour(GREEN, BLACK);
    printf("     |\\        \n");
    printf("    |   \\      \n");
    printf("    |    \\     \n");
    setColour(RED, BLACK);
    printf(".coovaa,   \\   \n");
    printf("88888888.coovaa,\n");
    printf("8888888800000000\n");
    printf("`YbbbdP'00000000\n");
    printf("        `YbbbdP'\n");
}

void bell() {
    setColour(ORANGE, BLACK);
    printf("                \n");
    printf("      .ca.      \n");
    printf("     (*88*)     \n");
    printf("    .888888.    \n");
    printf("   (88888888)   \n");
    printf("  .888****888.  \n");
    printf(" (8*__,");
    setColour(YELLOW, BLACK);
    printf("()");
    setColour(ORANGE, BLACK);
    printf(",__*8) \n");
    printf("                \n");
}

void lemmon() {
    setColour(YELLOW, BLACK);
    printf("       ...oa.   \n");
    printf("      8.cao88p  \n");
    printf("    8888888888  \n");
    printf("   88888888888  \n");
    printf("   88888888888  \n");
    printf("  .888888888`   \n");
    printf("  888888`       \n");
    printf("   `            \n");
}

void orange() {
    setColour(ORANGE, BLACK);
    printf("                \n");
    printf("    .cooaa,     \n");
    printf("   '8888");
    setColour(GREEN, BLACK);
    printf(".8.");
    setColour(ORANGE, BLACK);
    printf("8,   \n");
    printf("  '888888");
    setColour(GREEN, BLACK);
    printf("`");
    setColour(ORANGE, BLACK);
    printf("888,  \n");
    printf(" 1888888888888; \n");
    printf("  888888888888  \n");
    printf("   8888888888   \n");
    printf("    `YbbbdP'    \n");
}

void star() {
    setColour(PURPLE, BLACK);
    printf("       n        \n");
    printf("      /88\\     \n");
    printf("  ___/8888\\___\n");
    printf("  `888888888888` \n");
    printf("   \\888888888/  \n");
    printf("   /888/^8888\\   \n");
    printf("  /+./    \\.+\\   \n");
    printf("  :`        `;    \n");
}

void seven() {
    setColour(BLUE, BLACK);
    printf(".==============.\n");
    printf("`===========  =`\n");
    printf("           # #` \n");
    printf("          # #`  \n");
    printf("         # #`   \n");
    printf("        # #`    \n");
    printf("       # #`     \n");
    printf("      ###`      \n");
}

int main() {
    cherry();
    bell();
    lemmon();
    orange();
    star();
    seven();
    setColour(BRIGHT_WHITE, BLACK);
}