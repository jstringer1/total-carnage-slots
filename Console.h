#pragma once

#include <iostream>
#include <windows.h>

enum COLOUR {
    COLOUR_BLACK = 0,
    COLOUR_BLUE = 1,
    COLOUR_GREEN = 2,
    COLOUR_AQUA = 3,
    COLOUR_RED = 4,
    COLOUR_PURPLE = 5,
    COLOUR_ORANGE = 6,
    COLOUR_WHITE = 7,
    COLOUR_GREY = 8,
    COLOUR_LIGHT_BLUE = 9,
    COLOUR_LIGHT_GREEN = 10,
    COLOUR_LIGHT_AQUA = 11,
    COLOUR_LIGHT_RED = 12,
    COLOUR_LIGHT_PURPLE = 13,
    COLOUR_YELLOW = 14,
    COLOUR_BRIGHT_WHITE = 15
};

class Console {
public:
    Console();
    ~Console();
    HANDLE stdIn();
    HANDLE stdOut();
    void setColour(COLOUR foreground, COLOUR background);
    void setPosition(int x, int y);
    void setColourAndPosition(COLOUR foreground, COLOUR background, int x, int y);
    MOUSE_EVENT_RECORD waitForMouseEvent();
    COORD waitForMouseClick();
private:
    HANDLE in;
    HANDLE out;
};