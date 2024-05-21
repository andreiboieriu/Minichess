#pragma once

#include "adc.hpp"

enum class Button {
    LEFT,
    RIGHT,
    UP,
    DOWN,
    A,
    B,
    NONE
};

class ButtonManager {

public:
    ButtonManager(Adc &adc);

    Button getButtonPress();
    
private:
    Adc &mAdc;

};
