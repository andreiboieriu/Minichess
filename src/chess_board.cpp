#include "chess_board.hpp"

ChessBoard::ChessBoard(Display &display) : mDisplay(display) {
    init();
}

void ChessBoard::init() {
    reset();
    drawBoard();
}

void ChessBoard::reset() {
    // initialize board
    for (uint8_t row = 0; row < 4; row++) {
        for (uint8_t col = 0; col < 5; col++) {
            mBoard[row][col] = Piece::EMPTY;
        }
    }

    mBoard[0][0] = Piece::WHITE_ROOK;
    mBoard[0][3] = Piece::BLACK_PAWN;
    mBoard[0][4] = Piece::BLACK_KING;
    mBoard[1][0] = Piece::WHITE_BISHOP;
    mBoard[1][4] = Piece::BLACK_KNIGHT;
    mBoard[2][0] = Piece::WHITE_KNIGHT;
    mBoard[2][4] = Piece::BLACK_BISHOP;
    mBoard[3][0] = Piece::WHITE_KING;
    mBoard[3][1] = Piece::WHITE_PAWN;
    mBoard[3][4] = Piece::BLACK_ROOK;
}

void ChessBoard::drawBoard() {
    for (uint8_t row = 0; row < 4; row++) {
        for (uint8_t col = 0; col < 5; col++) {
            drawPiece(row, col, mBoard[row][col]);
        }
    }
}

void ChessBoard::drawPiece(uint8_t row, uint8_t col, Piece piece) {
    switch (piece) {
        case Piece::WHITE_PAWN:
            drawPawn(row, col, Color::WHITE);
            break;
        case Piece::BLACK_PAWN:
            drawPawn(row, col, Color::BLACK);
            break;
        case Piece::WHITE_BISHOP:
            drawBishop(row, col, Color::WHITE);
            break;
        case Piece::BLACK_BISHOP:
            drawBishop(row, col, Color::BLACK);
            break;
        case Piece::WHITE_KNIGHT:
            drawKnight(row, col, Color::WHITE);
            break;
        case Piece::BLACK_KNIGHT:
            drawKnight(row, col, Color::BLACK);
            break;
        case Piece::WHITE_ROOK:
            drawRook(row, col, Color::WHITE);
            break;
        case Piece::BLACK_ROOK:
            drawRook(row, col, Color::BLACK);
            break;
        case Piece::WHITE_KING:
            drawKing(row, col, Color::WHITE);
            break;
        case Piece::BLACK_KING:
            drawKing(row, col, Color::BLACK);
            break;
        case Piece::EMPTY:
            drawEmptySquare(row, col);
            break;
    }
}

void ChessBoard::drawKing(uint8_t row, uint8_t col, Color color) {
    uint8_t blackOnWhite[16][2] = {
        {63, 252},
        {223, 251},
        {47, 132},
        {23, 56},
        {23, 84},
        {17, 84},
        {44, 84},
        {210, 85},
        {210, 85},
        {44, 84},
        {17, 84},
        {23, 84},
        {23, 56},
        {47, 132},
        {223, 251},
        {63, 252},
    };

    uint8_t blackOnBlack[16][2] = {
        {0, 0},
        {192, 3},
        {32, 4},
        {16, 56},
        {16, 84},
        {16, 84},
        {44, 84},
        {210, 85},
        {210, 85},
        {44, 84},
        {16, 84},
        {16, 84},
        {16, 56},
        {32, 4},
        {192, 3},
        {0, 0},
    };

    Color squareColor = getSquareColor(row, col);

    if (color == Color::WHITE && squareColor == Color::WHITE) {
        drawValues(row, col, blackOnBlack, true);
    } else if (color == Color::WHITE && squareColor == Color::BLACK) {
        drawValues(row, col, blackOnWhite, true);
    } else if (color == Color::BLACK && squareColor == Color::WHITE) {
        drawValues(row, col, blackOnWhite);
    } else {
        drawValues(row, col, blackOnBlack);
    }
}

void ChessBoard::drawBishop(uint8_t row, uint8_t col, Color color) {
    uint8_t blackOnWhite[16][2] = {
        {255, 255},
        {255, 255},
        {255, 255},
        {63, 62},
        {223, 81},
        {47, 110},
        {21, 84},
        {10, 68},
        {138, 68},
        {85, 84},
        {47, 110},
        {223, 83},
        {63, 60},
        {255, 255},
        {255, 255},
        {255, 255}
    };

    uint8_t blackOnBlack[16][2] = {
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {192, 65},
        {32, 110},
        {16, 84},
        {10, 68},
        {138, 68},
        {80, 84},
        {32, 110},
        {192, 67},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0}
    };

    Color squareColor = getSquareColor(row, col);

    if (color == Color::WHITE && squareColor == Color::WHITE) {
        drawValues(row, col, blackOnBlack, true);
    } else if (color == Color::WHITE && squareColor == Color::BLACK) {
        drawValues(row, col, blackOnWhite, true);
    } else if (color == Color::BLACK && squareColor == Color::WHITE) {
        drawValues(row, col, blackOnWhite);
    } else {
        drawValues(row, col, blackOnBlack);
    }
}

void ChessBoard::drawRook(uint8_t row, uint8_t col, Color color) {
    uint8_t blackOnWhite[16][2] = {
        {255, 255},
        {255, 255},
        {224, 31},
        {222, 103},
        {50, 88},
        {214, 87},
        {21, 80},
        {18, 80},
        {18, 80},
        {21, 80},
        {214, 87},
        {50, 88},
        {222, 103},
        {224, 31},
        {255, 255},
        {255, 255}
    };

    uint8_t blackOnBlack[16][2] = {
        {0, 0},
        {0, 0},
        {0, 0},
        {30, 96},
        {50, 88},
        {214, 87},
        {20, 80},
        {18, 80},
        {18, 80},
        {20, 80},
        {214, 87},
        {50, 88},
        {30, 96},
        {0, 0},
        {0, 0},
        {0, 0}
    };

    Color squareColor = getSquareColor(row, col);

    if (color == Color::WHITE && squareColor == Color::WHITE) {
        drawValues(row, col, blackOnBlack, true);
    } else if (color == Color::WHITE && squareColor == Color::BLACK) {
        drawValues(row, col, blackOnWhite, true);
    } else if (color == Color::BLACK && squareColor == Color::WHITE) {
        drawValues(row, col, blackOnWhite);
    } else {
        drawValues(row, col, blackOnBlack);
    }
}

void ChessBoard::drawKnight(uint8_t row, uint8_t col, Color color) {
    uint8_t blackOnWhite[16][2] = {
        {159, 255},
        {111, 255},
        {151, 30},
        {139, 70},
        {85, 91},
        {75, 69},
        {32, 66},
        {225, 65},
        {19, 64},
        {0, 64},
        {5, 64},
        {59, 94},
        {199, 65},
        {31, 30},
        {255, 255},
        {255, 255}
    };

    uint8_t blackOnBlack[16][2] = {
        {0, 0},
        {96, 0},
        {144, 0},
        {136, 64},
        {84, 88},
        {75, 68},
        {32, 66},
        {224, 65},
        {19, 64},
        {0, 64},
        {4, 64},
        {56, 94},
        {192, 65},
        {0, 0},
        {0, 0},
        {0, 0}
    };

    Color squareColor = getSquareColor(row, col);

    if (color == Color::WHITE && squareColor == Color::WHITE) {
        drawValues(row, col, blackOnBlack, true);
    } else if (color == Color::WHITE && squareColor == Color::BLACK) {
        drawValues(row, col, blackOnWhite, true);
    } else if (color == Color::BLACK && squareColor == Color::WHITE) {
        drawValues(row, col, blackOnWhite);
    } else {
        drawValues(row, col, blackOnBlack);
    }
}

void ChessBoard::drawPawn(uint8_t row, uint8_t col, Color color) {
    uint8_t blackOnWhite[16][2] = {
        {255, 255},
        {255, 255},
        {255, 255},
        {255, 131},
        {255, 173},
        {39, 170},
        {219, 169},
        {37, 168},
        {37, 168},
        {219, 169},
        {39, 170},
        {255, 173},
        {255, 131},
        {255, 255},
        {255, 255},
        {255, 255}
    };

    uint8_t blackOnBlack[16][2] = {
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 44},
        {0, 42},
        {216, 41},
        {36, 40},
        {36, 40},
        {216, 41},
        {0, 42},
        {0, 44},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0}
    };

    Color squareColor = getSquareColor(row, col);

    if (color == Color::WHITE && squareColor == Color::WHITE) {
        drawValues(row, col, blackOnBlack, true);
    } else if (color == Color::WHITE && squareColor == Color::BLACK) {
        drawValues(row, col, blackOnWhite, true);
    } else if (color == Color::BLACK && squareColor == Color::WHITE) {
        drawValues(row, col, blackOnWhite);
    } else {
        drawValues(row, col, blackOnBlack);
    }
}

void ChessBoard::drawValues(uint8_t row, uint8_t col, uint8_t values[16][2], bool inverted) {
    for (uint8_t i = 0; i < 16; i++) {
        if (inverted) {
            values[i][0] = ~values[i][0];
            values[i][1] = ~values[i][1];
        }

        mDisplay.setValue((row * 2) * 128 + col * 16 + i, values[i][0]);
        mDisplay.setValue((row * 2 + 1) * 128 + col * 16 + i, values[i][1]);
    }
}

void ChessBoard::drawEmptySquare(uint8_t row, uint8_t col) {
    Color color = getSquareColor(row, col);

    for (uint8_t i = 0; i < 16; i++) {
        mDisplay.setValue((row * 2) * 128 + col * 16 + i, color == Color::BLACK ? 0 : 255);
        mDisplay.setValue((row * 2 + 1) * 128 + col * 16 + i, color == Color::BLACK ? 0 : 255);
    }
}

Color ChessBoard::getSquareColor(uint8_t row, uint8_t col) {
    uint8_t color = row % 2;

    if (col % 2) {
        color = 1 - color;
    }

    return color ? Color::WHITE : Color::BLACK;
}
