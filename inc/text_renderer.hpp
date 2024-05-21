#pragma once

#include "display.hpp"

class TextRenderer {

public:
    TextRenderer(Display &display);

    void renderLetter(uint8_t row, uint8_t col, char letter, uint8_t offset);
    void renderString(uint8_t row, uint8_t col, char str[], uint8_t offset);

private:
    Display &mDisplay;
};