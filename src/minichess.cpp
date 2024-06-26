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
                mainMenu(input, textRenderer, elapsedTime, chessBoard);
                break;

            case State::SELECTING_PIECE:
                pieceSelection(input, chessBoard, elapsedTime, textRenderer);
                break;

            case State::SELECTING_MOVE:
                moveSelection(input, chessBoard, elapsedTime, textRenderer);
                break;

            case State::END_SCREEN:
                endScreen(chessBoard, textRenderer, elapsedTime);
                break;
        }

        // display buffer
        display.display();

        mLastTime = mCurrentTime;
    }
}

void Minichess::mainMenu(Button input, TextRenderer &textRenderer, unsigned long elapsedTime, ChessBoard &chessBoard) {
    textRenderer.renderString(2, 3, "Minichess", 4);

    mTimeTilFlicker -= elapsedTime;

    if (mTimeTilFlicker <= 0) {
        mTimeTilFlicker = mFlickerCooldown;
        mRenderStart = 1 - mRenderStart;
    }

    if (mRenderStart) {
        textRenderer.renderString(4, 5, ">start", 0);
    }

    if (input == Button::A) {
        mState = State::SELECTING_PIECE;
        mTimeTilFlicker = mFlickerCooldown;
        mCanClick = false;
        mTimeTilClick = mClickCooldown;

        chessBoard.selectPlayer(Color::WHITE, mPieceSelectionPos);

        mPieceSelectionColor = chessBoard.getSquareDominantColor(mPieceSelectionPos[0], mPieceSelectionPos[1]);

        if (mPieceSelectionColor == Color::BLACK) {
            mPieceSelectionColor = Color::WHITE;
        } else {
            mPieceSelectionColor = Color::BLACK;
        }
    }
}

void Minichess::pieceSelection(Button input, ChessBoard &chessBoard, unsigned long elapsedTime, TextRenderer &textRenderer) {
    chessBoard.drawBoard();

    textRenderer.renderString(3, 10, "select", 3);
    textRenderer.renderString(4, 10, "piece", 6);

    mTimeTilFlicker -= elapsedTime;

    if (mTimeTilFlicker <= 0) {
        mTimeTilFlicker = mFlickerCooldown;
        
        mCanFlickerSelection = !mCanFlickerSelection;
    }

    if (!mCanClick) {
        // ignore input
        input = Button::NONE;

        mTimeTilClick -= elapsedTime;

        if (mTimeTilClick <= 0) {
            mTimeTilClick = mClickCooldown;

            mCanClick = true;
        }
    }

    chessBoard.movePieceSelection(input, mPieceSelectionPos);

    if (input != Button::NONE && input != Button::A && input != Button::B) {
        mPieceSelectionColor = chessBoard.getSquareDominantColor(mPieceSelectionPos[0], mPieceSelectionPos[1]);

        if (mPieceSelectionColor == Color::BLACK) {
            mPieceSelectionColor = Color::WHITE;
        } else {
            mPieceSelectionColor = Color::BLACK;
        }

        mTimeTilFlicker = mFlickerCooldown;
        mCanFlickerSelection = false;

        mCanClick = false;
        mTimeTilClick = mClickCooldown;
    }

    if (!mCanFlickerSelection) {
        chessBoard.drawSelection(mPieceSelectionPos[0], mPieceSelectionPos[1], mPieceSelectionColor);
    }

    if (input == Button::A) {
        mState = State::SELECTING_MOVE;
        mCanClick = false;
        mTimeTilClick = mClickCooldown;

        chessBoard.selectPiece(mPieceSelectionPos, mMoveSelectionPos);

        mMoveSelectionColor = chessBoard.getSquareDominantColor(mMoveSelectionPos[0], mMoveSelectionPos[1]);

        if (mMoveSelectionColor == Color::BLACK) {
            mMoveSelectionColor = Color::WHITE;
        } else {
            mMoveSelectionColor = Color::BLACK;
        }
    }
}

void Minichess::moveSelection(Button input, ChessBoard &chessBoard, unsigned long elapsedTime, TextRenderer &textRenderer) {
    chessBoard.drawBoard();

    textRenderer.renderString(3, 10, "select", 3);
    textRenderer.renderString(4, 11, "move", 3);

    mPieceSelectionColor = chessBoard.getSquareDominantColor(mPieceSelectionPos[0], mPieceSelectionPos[1]);

    if (mPieceSelectionColor == Color::BLACK) {
        mPieceSelectionColor = Color::WHITE;
    } else {
        mPieceSelectionColor = Color::BLACK;
    }

    chessBoard.drawSelection(mPieceSelectionPos[0],
                             mPieceSelectionPos[1],
                             mPieceSelectionColor);

    if (!mCanClick) {
        // ignore input
        input = Button::NONE;

        mTimeTilClick -= elapsedTime;

        if (mTimeTilClick <= 0) {
            mTimeTilClick = mClickCooldown;

            mCanClick = true;
        }
    }

    // go back to selecting a piece if B button is pressed
    if (input == Button::B) {
        mState = State::SELECTING_PIECE;

        mCanClick = false;
        mTimeTilClick = mClickCooldown;

        mTimeTilFlicker = mFlickerCooldown;
        mCanFlickerSelection = false;
    }

    // make move if button A is pressed
    if (input == Button::A) {
        mState = State::SELECTING_PIECE;

        mCanClick = false;
        mTimeTilClick = mClickCooldown;

        mTimeTilFlicker = mFlickerCooldown;
        mCanFlickerSelection = false;

        chessBoard.moveSelectedPiece(mMoveSelectionPos);

        // change player color
        if (mPlayerColor == Color::BLACK) {
            mPlayerColor = Color::WHITE;
        } else {
            mPlayerColor = Color::BLACK;
        }

        uint8_t res = chessBoard.selectPlayer(mPlayerColor, mPieceSelectionPos);

        mPieceSelectionColor = chessBoard.getSquareDominantColor(mPieceSelectionPos[0], mPieceSelectionPos[1]);

        if (mPieceSelectionColor == Color::BLACK) {
            mPieceSelectionColor = Color::WHITE;
        } else {
            mPieceSelectionColor = Color::BLACK;
        }

        if (!res) {
            if (chessBoard.isChecked(mPlayerColor)) {
                mGameResult = (mPlayerColor == Color::BLACK) ? GameResult::WHITE_WON : GameResult::BLACK_WON;
            } else {
                mGameResult = GameResult::DRAW;
            }

            mState = State::END_SCREEN;
        }

        // check insufficient material
        if (chessBoard.insufficientMaterial()) {
            mGameResult = GameResult::DRAW;

            mState = State::END_SCREEN;
        }
    }

    // draw indicators for possible moves
    chessBoard.drawMoves();

    // move and draw move selection if any moves are possible
    chessBoard.moveMoveSelection(input, mMoveSelectionPos);
    
    if (input != Button::NONE && input != Button::A && input != Button::B) {
        mMoveSelectionColor = chessBoard.getSquareDominantColor(mMoveSelectionPos[0], mMoveSelectionPos[1]);

        if (mMoveSelectionColor == Color::BLACK) {
            mMoveSelectionColor = Color::WHITE;
        } else {
            mMoveSelectionColor = Color::BLACK;
        }

        mTimeTilFlicker = mFlickerCooldown;
        mCanFlickerSelection = false;

        mCanClick = false;
        mTimeTilClick = mClickCooldown;
    }

    mTimeTilFlicker -= elapsedTime;

    if (mTimeTilFlicker <= 0) {
        mTimeTilFlicker = mFlickerCooldown;
        
        mCanFlickerSelection = !mCanFlickerSelection;
    }

    if (!mCanFlickerSelection) {
        chessBoard.drawSelection(mMoveSelectionPos[0], mMoveSelectionPos[1], mMoveSelectionColor);
    }
}

void Minichess::endScreen(ChessBoard &chessBoard, TextRenderer& textRenderer, unsigned long elapsedTime) {
    mEndScreenTimeLeft -= elapsedTime;

    if (mEndScreenTimeLeft <= 0) {
        mState = State::MAIN_MENU;
        chessBoard.reset();
        mPlayerColor = Color::WHITE;

        mEndScreenTimeLeft = mEndScreenTime;
        return;
    }

    chessBoard.drawBoard();

    if (mGameResult == GameResult::DRAW) {
        textRenderer.renderString(3, 11, "Draw!", 0);
    } else if (mGameResult == GameResult::WHITE_WON) {
        textRenderer.renderString(3, 10, "White", 6);
        textRenderer.renderString(4, 11, "wins!", 0);
    } else {
        textRenderer.renderString(3, 10, "Black", 6);
        textRenderer.renderString(4, 11, "wins!", 0);
    }
}
