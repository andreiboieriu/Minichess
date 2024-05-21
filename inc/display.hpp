#pragma once

#include "i2c.hpp"
#include "uart.hpp"
#include <string.h>

class Display {

public:
    Display(Twi &twi, Uart &uart);
    void display();

    void fill() {
        memset(mBuffer, 255, 1024);
    }

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
            // mBuffer[100 + (30 / 8) * mWidth] |= (1 << (30 % 8));

        } else {
            mBuffer[x + (y / 8) * mWidth] |= (1 << (y % 8));
            // mBuffer[100 + (35 / 8) * mWidth] |= (1 << (35 % 8));
        }
    }

    void awala() {
        for (uint16_t i = 0; i < 1024; i++) {
            if (mBuffer[i] != 255) {
                mUart.puts("sugpulaaa\r\n");
            }
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