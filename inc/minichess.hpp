#pragma once

#include "uart.hpp"
#include "adc.hpp"
#include "i2c.hpp"

#include "button_manager.hpp"
#include "text_renderer.hpp"
#include "chess_board.hpp"

class Minichess {

public:
    Minichess();
    ~Minichess();

    void run();

private:
    enum class State {
        MAIN_MENU,
        PLAYING
    };

    void init();
    void mainMenu(Button input, TextRenderer &textRenderer, unsigned long elapsedTime);
    void playing(Button input, ChessBoard &chessBoard, unsigned long elapsedTime);

    State mState;

    Twi mTwi;
    Uart mUart;
    Adc mAdc;

    unsigned long mCurrentTime;
    unsigned long mLastTime;

    bool mRenderStart = true;
    int16_t mStartFlickerCooldown = 800;

    bool whiteTurn = true;
};
