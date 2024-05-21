#include "minichess.hpp"

#include "button_manager.hpp"
#include "chess_board.hpp"
#include "display.hpp"

#include <util/delay.h>

Minichess::Minichess() {
    init();
}

Minichess::~Minichess() {

}

void Minichess::init() {

}

void Minichess::run() {
    ButtonManager buttonManager(mAdc);
    Display display(mTwi, mUart);
    ChessBoard chessBoard(display);

    while (1) {
        Button button = buttonManager.getButtonPress();


        _delay_ms(500);

        display.display();
    }
}

