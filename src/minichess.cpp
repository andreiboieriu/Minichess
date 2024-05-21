#include "minichess.hpp"

#include "display.hpp"
#include "millis.hpp"

#include <util/delay.h>

Minichess::Minichess() {
    init();
}

Minichess::~Minichess() {

}

void Minichess::init() {
    init_millis(F_CPU);
    mState = State::MAIN_MENU;
}

void Minichess::run() {
    ButtonManager buttonManager(mAdc);
    Display display(mTwi, mUart);
    ChessBoard chessBoard(display);
    TextRenderer textRenderer(display);

    mLastTime = millis();

    while (1) {
        // clear display
        display.clear();

        // get elapsed time
        mCurrentTime = millis();
        unsigned long elapsedTime = mCurrentTime - mLastTime;

        // get input
        Button input = buttonManager.getButtonPress();

        switch (mState) {
            case State::MAIN_MENU:
                mainMenu(input, textRenderer, elapsedTime);
                break;
            case State::PLAYING:
                playing(input, chessBoard, elapsedTime);
                break;
        }

        // display buffer
        display.display();

        mLastTime = mCurrentTime;
    }
}

void Minichess::mainMenu(Button input, TextRenderer &textRenderer, unsigned long elapsedTime) {
    textRenderer.renderString(2, 3, "Minichess", 4);

    mStartFlickerCooldown -= elapsedTime;
    mUart.putU16(elapsedTime);
    mUart.puts("\r\n");

    if (mStartFlickerCooldown <= 0) {
        mStartFlickerCooldown = 800;
        mRenderStart = 1 - mRenderStart;
    }

    if (mRenderStart) {
        textRenderer.renderString(4, 5, ">start", 0);
    }

    if (input == Button::A) {
        mState = State::PLAYING;
    }
}

void Minichess::playing(Button input, ChessBoard &chessBoard, unsigned long elapsedTime) {
    chessBoard.drawBoard();

    chessBoard.drawSelection(0, 1, Color::BLACK);


}

