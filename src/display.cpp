#include "display.hpp"

Display::Display(Twi &twi, Uart &uart) :
                 mTwi(twi), mUart(uart) {
    init();
}

void Display::init() {
    // find i2c address
    mTwi.discover(&mAddress);

    mUart.putU8(mAddress);

    command((uint8_t)0xAE);
    command((uint8_t)0xD5);
    command((uint8_t)0x80);
    command((uint8_t)0xA8);
    command((uint8_t)63);
    command((uint8_t)0xD3);
    command((uint8_t)0x0);
    command((uint8_t)0x40);
    command((uint8_t)0x8D);
    command((uint8_t)0x14); // or 0x10
    command((uint8_t)0x20);
    command((uint8_t)0x00);
    command((uint8_t)0xA0 | 0x1);
    command((uint8_t)0xC8);

    command((uint8_t)0xDA);
    command((uint8_t)0x12);

    command((uint8_t)0x81);
    command((uint8_t)0xCF);

    command((uint8_t)0xD9);
    command((uint8_t)0xF1);

    command((uint8_t)0xDB);
    command((uint8_t)0x40);
    command((uint8_t)0xA4);
    command((uint8_t)0xA6);
    command((uint8_t)0x2E);
    command((uint8_t)0xAF);

    clear();
}

void Display::display() {
    command((uint8_t)0x22);
    command((uint8_t)0);
    command((uint8_t)0xFF);
    command((uint8_t)0x21);
    command((uint8_t)0);

    command((uint8_t)mWidth - 1);

    // uint16_t count = mWidth * ((mHeight + 7) / 8);
    uint16_t count = 1024;

    uint8_t *ptr = mBuffer;

    mTwi.start();
    mTwi.write(mAddress << 1);
    mTwi.write((uint8_t)0x40);

    uint16_t sentBytes = 1;

    while (count--) {
        if (sentBytes >= 2000) {
            // mTwi.stop();
            // mTwi.start();
            // mTwi.write(mAddress << 1);
            // mTwi.write((uint8_t)0x40);
            sentBytes = 1;
        }

        // mTwi.start();
        // mTwi.write(mAddress << 1);
        // mTwi.write((uint8_t)0x40);
        mTwi.write(*ptr++);
        // mTwi.stop();
        sentBytes++;
    }

    mTwi.stop();
}

void Display::command(uint8_t value) {
    mTwi.start();
    mTwi.write(mAddress << 1);
    mTwi.write((uint8_t)0x00);
    mTwi.write(value);
    mTwi.stop();
}
