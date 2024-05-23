#pragma once

#include "inttypes.h"
#include "button_manager.hpp"
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

    void drawMoves();
    int8_t getMoveCount();
    void selectPiece(int8_t piecePos[], int8_t moveSelectionPos[]);
    void moveSelectedPiece(int8_t dest[]);

    void movePieceSelection(Color playerColor, Button input, int8_t selectionPos[]);
    void moveMoveSelection(Button input, int8_t selectionPos[]);

    Color getSquareDominantColor(uint8_t row, uint8_t col);

private:
    void drawEmptySquare(uint8_t row, uint8_t col);

    void drawKing(uint8_t row, uint8_t col, Color color);
    void drawBishop(uint8_t row, uint8_t col, Color color);
    void drawRook(uint8_t row, uint8_t col, Color color);
    void drawKnight(uint8_t row, uint8_t col, Color color);
    void drawPawn(uint8_t row, uint8_t col, Color color);

    void drawPiece(uint8_t row, uint8_t col, Piece piece);
    void drawValues(uint8_t row, uint8_t col, uint8_t values[16][2], bool inverted = false);
    void drawMoveIndicator(uint8_t row, uint8_t col, Color color);

    void getPossibleMoves();
    void getPawnMoves(int8_t piecePos[], Color color);
    void getBishopMoves(int8_t piecePos[], Color color);
    void getKnightMoves(int8_t piecePos[], Color color);
    void getRookMoves(int8_t piecePos[], Color color);
    void getKingMoves(int8_t piecePos[], Color color);

    void validateMoves();
    bool isChecked(Color playerColor, Piece board[4][5]);


    Color getSquareColor(uint8_t row, uint8_t col);

    Color getPieceColor(Piece piece);

    Piece mBoard[4][5];
    uint8_t mMoves[4][5];
    int8_t mSelectedPiecePos[2];

    Display &mDisplay;

    bool mWhitePawnMoved = false;
    bool mBlackPawnMoved = false;
};
