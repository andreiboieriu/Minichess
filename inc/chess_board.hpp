#pragma once

#include "inttypes.h"
#include "display.hpp"

enum class Piece {
    WHITE_PAWN,
    WHITE_KNIGHT,
    WHITE_ROOK,
    WHITE_BISHOP,
    WHITE_KING,
    BLACK_PAWN,
    BLACK_KNIGHT,
    BLACK_ROOK,
    BLACK_BISHOP,
    BLACK_KING,
    EMPTY
};

enum class Color {
    WHITE,
    BLACK
};

class ChessBoard {

public:


    ChessBoard(Display &display);

    void init();
    void reset();
    void drawBoard();
    void drawSelection(uint8_t row, uint8_t col, Color color);

    void selectPiece() {

    }

private:
    void drawEmptySquare(uint8_t row, uint8_t col);

    void drawKing(uint8_t row, uint8_t col, Color color);
    void drawBishop(uint8_t row, uint8_t col, Color color);
    void drawRook(uint8_t row, uint8_t col, Color color);
    void drawKnight(uint8_t row, uint8_t col, Color color);
    void drawPawn(uint8_t row, uint8_t col, Color color);

    void drawPiece(uint8_t row, uint8_t col, Piece piece);

    void drawValues(uint8_t row, uint8_t col, uint8_t values[16][2], bool inverted = false);


    Color getSquareColor(uint8_t row, uint8_t col);

    Piece mBoard[4][5];

    Display &mDisplay;

    uint8_t mSelectedPiece[2];
};
