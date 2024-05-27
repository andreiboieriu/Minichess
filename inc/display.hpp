#pragma once

#include "i2c.hpp"
#include "uart.hpp"
#include <string.h>

class Display {

public:
    Display(Twi &twi, Uart &uart);
    void display();

    void clear() {
        memset(mBuffer, 0, 1024);
    }

    // modifies 8 pixels at once
    void setValue(int idx, uint8_t value) {
        mBuffer[idx] = value;
    }

    void drawPixel(uint8_t x, uint8_t y, uint8_t color) {
        if (!color) {
            mBuffer[x + (y / 8) * mWidth] &= ~(1 << (y % 8));
        } else {
            mBuffer[x + (y / 8) * mWidth] |= (1 << (y % 8));
        }
    }

private:
    void init();

    void command(uint8_t value);

    const uint8_t mWidth = 128;
    const uint8_t mHeight = 64;

    Twi &mTwi;
    Uart &mUart;
    uint8_t mAddress;
    uint8_t mBuffer[1024] = {};
};