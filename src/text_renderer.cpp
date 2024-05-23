#include "text_renderer.hpp"

TextRenderer::TextRenderer(Display &display) : mDisplay(display) {

}

void TextRenderer::renderLetter(uint8_t row, uint8_t col, char letter,uint8_t offset) {
    switch (letter) {
        case 'M':
            mDisplay.setValue(row * 128 + col * 8 + offset, 127);
            mDisplay.setValue(row * 128 + col * 8 + 1 + offset, 127);
            mDisplay.setValue(row * 128 + col * 8 + 2 + offset, 6);
            mDisplay.setValue(row * 128 + col * 8 + 3 + offset, 12);
            mDisplay.setValue(row * 128 + col * 8 + 4 + offset, 6);
            mDisplay.setValue(row * 128 + col * 8 + 5 + offset, 127);
            mDisplay.setValue(row * 128 + col * 8 + 6 + offset, 127);
            mDisplay.setValue(row * 128 + col * 8 + 7 + offset, 0);
            break;

        case 'i':
            mDisplay.setValue(row * 128 + col * 8 + offset, 0);
            mDisplay.setValue(row * 128 + col * 8 + 1 + offset, 0);
            mDisplay.setValue(row * 128 + col * 8 + 2 + offset, 61);
            mDisplay.setValue(row * 128 + col * 8 + 3 + offset, 125);
            mDisplay.setValue(row * 128 + col * 8 + 4 + offset, 64);
            mDisplay.setValue(row * 128 + col * 8 + 5 + offset, 0);
            mDisplay.setValue(row * 128 + col * 8 + 6 + offset, 0);
            mDisplay.setValue(row * 128 + col * 8 + 7 + offset, 0);
            break;

        case 'n':
            mDisplay.setValue(row * 128 + col * 8 + offset, 124);
            mDisplay.setValue(row * 128 + col * 8 + 1 + offset, 124);
            mDisplay.setValue(row * 128 + col * 8 + 2 + offset, 4);
            mDisplay.setValue(row * 128 + col * 8 + 3 + offset, 4);
            mDisplay.setValue(row * 128 + col * 8 + 4 + offset, 4);
            mDisplay.setValue(row * 128 + col * 8 + 5 + offset, 124);
            mDisplay.setValue(row * 128 + col * 8 + 6 + offset, 120);
            mDisplay.setValue(row * 128 + col * 8 + 7 + offset, 0);
            break;

        case 'c':
            mDisplay.setValue(row * 128 + col * 8 + offset, 56);
            mDisplay.setValue(row * 128 + col * 8 + 1 + offset, 124);
            mDisplay.setValue(row * 128 + col * 8 + 2 + offset, 68);
            mDisplay.setValue(row * 128 + col * 8 + 3 + offset, 68);
            mDisplay.setValue(row * 128 + col * 8 + 4 + offset, 108);
            mDisplay.setValue(row * 128 + col * 8 + 5 + offset, 40);
            mDisplay.setValue(row * 128 + col * 8 + 6 + offset, 0);
            mDisplay.setValue(row * 128 + col * 8 + 7 + offset, 0);
            break;

        case 'h':
            mDisplay.setValue(row * 128 + col * 8 + offset, 127);
            mDisplay.setValue(row * 128 + col * 8 + 1 + offset, 127);
            mDisplay.setValue(row * 128 + col * 8 + 2 + offset, 4);
            mDisplay.setValue(row * 128 + col * 8 + 3 + offset, 4);
            mDisplay.setValue(row * 128 + col * 8 + 4 + offset, 4);
            mDisplay.setValue(row * 128 + col * 8 + 5 + offset, 124);
            mDisplay.setValue(row * 128 + col * 8 + 6 + offset, 120);
            mDisplay.setValue(row * 128 + col * 8 + 7 + offset, 0);
            break;

        case 'e':
            mDisplay.setValue(row * 128 + col * 8 + offset, 0);
            mDisplay.setValue(row * 128 + col * 8 + 1 + offset, 56);
            mDisplay.setValue(row * 128 + col * 8 + 2 + offset, 124);
            mDisplay.setValue(row * 128 + col * 8 + 3 + offset, 84);
            mDisplay.setValue(row * 128 + col * 8 + 4 + offset, 84);
            mDisplay.setValue(row * 128 + col * 8 + 5 + offset, 92);
            mDisplay.setValue(row * 128 + col * 8 + 6 + offset, 24);
            mDisplay.setValue(row * 128 + col * 8 + 7 + offset, 0);
            break;

        case 's':
            mDisplay.setValue(row * 128 + col * 8 + offset, 0);
            mDisplay.setValue(row * 128 + col * 8 + 1 + offset, 8);
            mDisplay.setValue(row * 128 + col * 8 + 2 + offset, 92);
            mDisplay.setValue(row * 128 + col * 8 + 3 + offset, 84);
            mDisplay.setValue(row * 128 + col * 8 + 4 + offset, 84);
            mDisplay.setValue(row * 128 + col * 8 + 5 + offset, 116);
            mDisplay.setValue(row * 128 + col * 8 + 6 + offset, 32);
            mDisplay.setValue(row * 128 + col * 8 + 7 + offset, 0);
            break;

        case 't':
            mDisplay.setValue(row * 128 + col * 8 + offset, 0);
            mDisplay.setValue(row * 128 + col * 8 + 1 + offset, 4);
            mDisplay.setValue(row * 128 + col * 8 + 2 + offset, 63);
            mDisplay.setValue(row * 128 + col * 8 + 3 + offset, 127);
            mDisplay.setValue(row * 128 + col * 8 + 4 + offset, 68);
            mDisplay.setValue(row * 128 + col * 8 + 5 + offset, 68);
            mDisplay.setValue(row * 128 + col * 8 + 6 + offset, 0);
            mDisplay.setValue(row * 128 + col * 8 + 7 + offset, 0);
            break;

        case 'a':
            mDisplay.setValue(row * 128 + col * 8 + offset, 0);
            mDisplay.setValue(row * 128 + col * 8 + 1 + offset, 32);
            mDisplay.setValue(row * 128 + col * 8 + 2 + offset, 116);
            mDisplay.setValue(row * 128 + col * 8 + 3 + offset, 84);
            mDisplay.setValue(row * 128 + col * 8 + 4 + offset, 84);
            mDisplay.setValue(row * 128 + col * 8 + 5 + offset, 124);
            mDisplay.setValue(row * 128 + col * 8 + 6 + offset, 120);
            mDisplay.setValue(row * 128 + col * 8 + 7 + offset, 0);
            break;

        case 'r':
            mDisplay.setValue(row * 128 + col * 8 + offset, 0);
            mDisplay.setValue(row * 128 + col * 8 + 1 + offset, 124);
            mDisplay.setValue(row * 128 + col * 8 + 2 + offset, 124);
            mDisplay.setValue(row * 128 + col * 8 + 3 + offset, 4);
            mDisplay.setValue(row * 128 + col * 8 + 4 + offset, 4);
            mDisplay.setValue(row * 128 + col * 8 + 5 + offset, 12);
            mDisplay.setValue(row * 128 + col * 8 + 6 + offset, 8);
            mDisplay.setValue(row * 128 + col * 8 + 7 + offset, 0);
            break;

        case '>':
            mDisplay.setValue(row * 128 + col * 8 + offset, 0);
            mDisplay.setValue(row * 128 + col * 8 + 1 + offset, 0);
            mDisplay.setValue(row * 128 + col * 8 + 2 + offset, 68);
            mDisplay.setValue(row * 128 + col * 8 + 3 + offset, 108);
            mDisplay.setValue(row * 128 + col * 8 + 4 + offset, 56);
            mDisplay.setValue(row * 128 + col * 8 + 5 + offset, 16);
            mDisplay.setValue(row * 128 + col * 8 + 6 + offset, 0);
            mDisplay.setValue(row * 128 + col * 8 + 7 + offset, 0);
            break;

        default:
            break;
    }
}

void TextRenderer::renderString(uint8_t row, uint8_t col, char str[], uint8_t offset) {
    for (int i = 0; str[i]; i++) {
        renderLetter(row, col + i, str[i], offset);
    }
}
