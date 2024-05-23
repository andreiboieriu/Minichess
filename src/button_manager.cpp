#include "button_manager.hpp"

ButtonManager::ButtonManager(Adc &adc) : mAdc(adc) {

}

Button ButtonManager::getButtonPress() {
    uint16_t value = mAdc.read(0);

    if (value <= 815 && value >= 785) {
        return Button::LEFT;
    } else if (value <= 755 && value >= 725) {
        return Button::RIGHT;
    } else if (value <= 885 && value >= 855) {
        return Button::UP;
    } else if (value <= 1019 && value >= 1009) {
        return Button::DOWN;
    } else if (value <= 965 && value >= 935) {
        return Button::A;
    } else if (value <= 1006 && value >= 985) {
        return Button::B;
    } else {
        return Button::NONE;
    }
}