#pragma once

#include "uart.hpp"
#include "adc.hpp"
#include "i2c.hpp"

class Minichess {

public:
    Minichess();
    ~Minichess();

    void run();

private:
    void init();

    Twi mTwi;
    Uart mUart;
    Adc mAdc;
};
