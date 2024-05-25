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
        SELECTING_PIECE,
        SELECTING_MOVE
    };

    void init();
    void mainMenu(Button input, TextRenderer &textRenderer, unsigned long elapsedTime, ChessBoard &chessBoard);
    void pieceSelection(Button input, ChessBoard &chessBoard, unsigned long elapsedTime);
    void moveSelection(Button input, ChessBoard &chessBoard, unsigned long elapsedTime);

    State mState;

    Twi mTwi;
    Uart mUart;
    Adc mAdc;

    unsigned long mCurrentTime;
    unsigned long mLastTime;

    bool mRenderStart = true;
    const int16_t mFlickerCooldown = 800;
    int16_t mTimeTilFlicker = mFlickerCooldown;

    Color mPieceSelectionColor = Color::BLACK;
    Color mMoveSelectionColor = Color::BLACK;

    int8_t mPieceSelectionPos[2] = {0, 0};
    int8_t mMoveSelectionPos[2] = {0, 0};

    bool mCanFlickerSelection = false;
    bool mCanClick = true;

    const int16_t mClickCooldown = 200;
    int16_t mTimeTilClick = mClickCooldown;

    Color mPlayerColor = Color::WHITE;
};
