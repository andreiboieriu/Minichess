#pragma once

#include <inttypes.h>

class Uart {

public:
    Uart();

    void putc(unsigned char data);
    void puts(char* s);
    void putU8(uint8_t val);
    void putU16(uint16_t val);

    unsigned char getc(void);

private:
    void init();

    const uint16_t UBRR115200 = 8;
};
