#pragma once

#include <inttypes.h>

class Adc {

public:
    Adc();

    uint16_t read(uint8_t channel);

private:
    void init();
};
