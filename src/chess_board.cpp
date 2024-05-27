#include "chess_board.hpp"

ChessBoard::ChessBoard(Display &display) : mDisplay(display) {
    init();
}

void ChessBoard::init() {
    reset();
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

    mSelectedPiecePos[0] = 0;
    mSelectedPiecePos[1] = 0;

    mWhitePawnMoved = false;
    mBlackPawnMoved = false;
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

void ChessBoard::drawSelection(uint8_t row, uint8_t col, Color color) {
    for (uint8_t i = 4; i < 12; i++) {
        for (uint8_t j = 4; j < 12; j++) {
            if ((i == 4 && j < 6) || (i == 4 && j > 9))
                continue;

            if ((i == 5 && j < 5) || (i == 5 && j > 10))
                continue;

            if ((i == 10 && j < 5) || (i == 10 && j > 10))
                continue;

            if ((i == 11 && j < 6) || (i == 11 && j > 9))
                continue;

            mDisplay.drawPixel(col * 16 + i, row * 16 + j, color == Color::BLACK ? 0 : 1);
        }
    }
}

Color ChessBoard::getSquareDominantColor(uint8_t row, uint8_t col) {
    Piece piece = mBoard[row][col];

    if (piece == Piece::EMPTY) {
        return getSquareColor(row, col);
    }

    return getPieceColor(piece);
}

Color ChessBoard::getPieceColor(Piece piece) {
    return (piece == Piece::WHITE_BISHOP ||
            piece == Piece::WHITE_KING ||
            piece == Piece::WHITE_PAWN ||
            piece == Piece::WHITE_ROOK ||
            piece == Piece::WHITE_KNIGHT) ? Color::WHITE : Color::BLACK;
}

void ChessBoard::movePieceSelection(Button input, int8_t selectionPos[]) {
    // get direction based on input
    int8_t direction[2] = {0, 0};

    switch (input) {
        case Button::RIGHT:
            direction[0] = 0;
            direction[1] = 1;

            break;

        case Button::LEFT:
            direction[0] = 0;
            direction[1] = -1;

            break;

        case Button::UP:
            direction[0] = -1;
            direction[1] = 0;

            break;

        case Button::DOWN:
            direction[0] = 1;
            direction[1] = 0;

            break;

        default:
            return;
    }

    int8_t currPos[2];
    currPos[0] = selectionPos[0];
    currPos[1] = selectionPos[1];

    do {
        currPos[0] += direction[0];
        currPos[1] += direction[1];

        if (currPos[1] < 0) {
            currPos[1] = 4;
            currPos[0] -= 1;

            if (currPos[0] < 0) {
                currPos[0] = 3;
            }
        } else if (currPos[1] >= 5) {
            currPos[1] = 0;
            currPos[0] += 1;

            if (currPos[0] >= 4) {
                currPos[0] = 0;
            }

        } else if (currPos[0] < 0) {
            currPos[0] = 3;
            currPos[1] -= 1;

            if (currPos[1] < 0) {
                currPos[1] = 4;
            }
        } else if (currPos[0] >= 4) {
            currPos[0] = 0;
            currPos[1] += 1;

            if (currPos[1] >= 5) {
                currPos[1] = 0;
            }
        }

        if (mPieces[currPos[0]][currPos[1]]) {
            break;
        }

    } while (!(currPos[0] == selectionPos[0] && currPos[1] == selectionPos[1]));

    selectionPos[0] = currPos[0];
    selectionPos[1] = currPos[1];
}

void ChessBoard::moveMoveSelection(Button input, int8_t selectionPos[]) {
    // get direction based on input
    int8_t direction[2] = {0, 0};

    uint8_t pieceIdx = getPieceIdx(mBoard[mSelectedPiecePos[0]][mSelectedPiecePos[1]]);

    switch (input) {
        case Button::RIGHT:
            direction[0] = 0;
            direction[1] = 1;

            break;

        case Button::LEFT:
            direction[0] = 0;
            direction[1] = -1;

            break;

        case Button::UP:
            direction[0] = -1;
            direction[1] = 0;

            break;

        case Button::DOWN:
            direction[0] = 1;
            direction[1] = 0;

            break;

        default:
            return;
    }

    int8_t currPos[2];
    currPos[0] = selectionPos[0];
    currPos[1] = selectionPos[1];

    do {
        currPos[0] += direction[0];
        currPos[1] += direction[1];

        if (currPos[1] < 0) {
            currPos[1] = 4;
            currPos[0] -= 1;

            if (currPos[0] < 0) {
                currPos[0] = 3;
            }
        } else if (currPos[1] >= 5) {
            currPos[1] = 0;
            currPos[0] += 1;

            if (currPos[0] >= 4) {
                currPos[0] = 0;
            }

        } else if (currPos[0] < 0) {
            currPos[0] = 3;
            currPos[1] -= 1;

            if (currPos[1] < 0) {
                currPos[1] = 4;
            }
        } else if (currPos[0] >= 4) {
            currPos[0] = 0;
            currPos[1] += 1;

            if (currPos[1] >= 5) {
                currPos[1] = 0;
            }
        }

        if (mMoves[pieceIdx][currPos[0]][currPos[1]]) {
            break;
        }

    } while (!(currPos[0] == selectionPos[0] && currPos[1] == selectionPos[1]));

    selectionPos[0] = currPos[0];
    selectionPos[1] = currPos[1];
}

void ChessBoard::getPossibleMoves() {
    // get piece
    Piece piece = mBoard[mSelectedPiecePos[0]][mSelectedPiecePos[1]];
    uint8_t pieceIdx = getPieceIdx(piece);
    Color pieceColor = getPieceColor(piece);

    // clear moves matrix
    for (uint8_t row = 0; row < 4; row++) {
        for (uint8_t col = 0; col < 5; col++) {
            mMoves[pieceIdx][row][col] = 0;
        }
    }

    if (piece == Piece::BLACK_PAWN || piece == Piece::WHITE_PAWN) {
        getPawnMoves(mSelectedPiecePos, pieceColor);
    } else if (piece == Piece::BLACK_BISHOP || piece == Piece::WHITE_BISHOP) {
        getBishopMoves(mSelectedPiecePos, pieceColor);
    } else if (piece == Piece::BLACK_KNIGHT || piece == Piece::WHITE_KNIGHT) {
        getKnightMoves(mSelectedPiecePos, pieceColor);
    } else if (piece == Piece::BLACK_ROOK || piece == Piece::WHITE_ROOK) {
        getRookMoves(mSelectedPiecePos, pieceColor);
    } else if (piece == Piece::BLACK_KING || piece == Piece::WHITE_KING) {
        getKingMoves(mSelectedPiecePos, pieceColor);
    }
}

void ChessBoard::getPawnMoves(int8_t piecePos[], Color color) {
    // check if pawn can move 2 squares
    if (color == Color::WHITE && !mWhitePawnMoved && mBoard[piecePos[0]][piecePos[1] + 1] == Piece::EMPTY) {
        Piece piece = mBoard[piecePos[0]][piecePos[1] + 2];

        if (piece == Piece::EMPTY) {
            mMoves[0][piecePos[0]][piecePos[1] + 2] = 1;
        }
    }

    if (color == Color::BLACK && !mBlackPawnMoved && mBoard[piecePos[0]][piecePos[1] - 1] == Piece::EMPTY) {
        Piece piece = mBoard[piecePos[0]][piecePos[1] - 2];

        if (piece == Piece::EMPTY) {
            mMoves[0][piecePos[0]][piecePos[1] - 2] = 1;
        }
    }

    // check if pawn can move 1 square
    if (color == Color::WHITE && piecePos[1] + 1 < 5 && mBoard[piecePos[0]][piecePos[1] + 1] == Piece::EMPTY) {
        mMoves[0][piecePos[0]][piecePos[1] + 1] = 1;
    }

    // check if pawn can attack
    if (color == Color::WHITE && piecePos[1] + 1 < 5 && piecePos[0] - 1 >= 0) {
        Piece piece = mBoard[piecePos[0] - 1][piecePos[1] + 1];

        if (piece != Piece::EMPTY && getPieceColor(piece) != color && piece != Piece::WHITE_KING && piece != Piece::BLACK_KING) {
            mMoves[0][piecePos[0] - 1][piecePos[1] + 1] = 1;
        }
    }

    if (color == Color::WHITE && piecePos[1] + 1 < 5 && piecePos[0] + 1 < 4) {
        Piece piece = mBoard[piecePos[0] + 1][piecePos[1] + 1];

        if (piece != Piece::EMPTY && getPieceColor(piece) != color && piece != Piece::WHITE_KING && piece != Piece::BLACK_KING) {
            mMoves[0][piecePos[0] + 1][piecePos[1] + 1] = 1;
        }
    }

    // check if pawn can move 1 square
    if (color == Color::BLACK && piecePos[1] - 1 >= 0 && mBoard[piecePos[0]][piecePos[1] - 1] == Piece::EMPTY) {
        mMoves[0][piecePos[0]][piecePos[1] - 1] = 1;
    }

    // check if pawn can attack
    if (color == Color::BLACK && piecePos[1] - 1 >= 0 && piecePos[0] - 1 >= 0) {
        Piece piece = mBoard[piecePos[0] - 1][piecePos[1] - 1];

        if (piece != Piece::EMPTY && getPieceColor(piece) != color && piece != Piece::WHITE_KING && piece != Piece::BLACK_KING) {
            mMoves[0][piecePos[0] - 1][piecePos[1] - 1] = 1;
        }
    }

    if (color == Color::BLACK && piecePos[1] - 1 >= 0 && piecePos[0] + 1 < 4) {
        Piece piece = mBoard[piecePos[0] + 1][piecePos[1] - 1];

        if (piece != Piece::EMPTY && getPieceColor(piece) != color && piece != Piece::WHITE_KING && piece != Piece::BLACK_KING) {
            mMoves[0][piecePos[0] + 1][piecePos[1] - 1] = 1;
        }
    }
}

void ChessBoard::drawMoves() {
    uint8_t pieceIdx = getPieceIdx(mBoard[mSelectedPiecePos[0]][mSelectedPiecePos[1]]);

    for (uint8_t row = 0; row < 4; row++) {
        for (uint8_t col = 0; col < 5; col++) {
            if (!mMoves[pieceIdx][row][col]) {
                continue;
            }

            // get indicator color
            Color color = getSquareDominantColor(row, col);

            if (color == Color::BLACK) {
                color = Color::WHITE;
            } else {
                color = Color::BLACK;
            }

            // draw indicator
            drawMoveIndicator(row, col, color);
        }
    }
}

void ChessBoard::selectPiece(int8_t piecePos[], int8_t moveSelectionPos[]) {
    mSelectedPiecePos[0] = piecePos[0];
    mSelectedPiecePos[1] = piecePos[1];

    uint8_t pieceIdx = getPieceIdx(mBoard[mSelectedPiecePos[0]][mSelectedPiecePos[1]]);

    for (uint8_t row = 0; row < 4; row++) {
        for (uint8_t col = 0; col < 5; col++) {
            if (mMoves[pieceIdx][row][col]) {
                moveSelectionPos[0] = row;
                moveSelectionPos[1] = col;
                break;
            }
        }
    }
}

void ChessBoard::drawMoveIndicator(uint8_t row, uint8_t col, Color color) {
    mDisplay.drawPixel(col * 16 + 4, row * 16 + 6, color == Color::BLACK ? 0 : 1);
    mDisplay.drawPixel(col * 16 + 4, row * 16 + 7, color == Color::BLACK ? 0 : 1);
    mDisplay.drawPixel(col * 16 + 4, row * 16 + 8, color == Color::BLACK ? 0 : 1);
    mDisplay.drawPixel(col * 16 + 4, row * 16 + 9, color == Color::BLACK ? 0 : 1);

    mDisplay.drawPixel(col * 16 + 5, row * 16 + 5, color == Color::BLACK ? 0 : 1);
    mDisplay.drawPixel(col * 16 + 5, row * 16 + 6, color == Color::BLACK ? 0 : 1);
    mDisplay.drawPixel(col * 16 + 5, row * 16 + 9, color == Color::BLACK ? 0 : 1);
    mDisplay.drawPixel(col * 16 + 5, row * 16 + 10, color == Color::BLACK ? 0 : 1);

    mDisplay.drawPixel(col * 16 + 6, row * 16 + 4, color == Color::BLACK ? 0 : 1);
    mDisplay.drawPixel(col * 16 + 6, row * 16 + 5, color == Color::BLACK ? 0 : 1);
    mDisplay.drawPixel(col * 16 + 6, row * 16 + 10, color == Color::BLACK ? 0 : 1);
    mDisplay.drawPixel(col * 16 + 6, row * 16 + 11, color == Color::BLACK ? 0 : 1);

    mDisplay.drawPixel(col * 16 + 7, row * 16 + 4, color == Color::BLACK ? 0 : 1);
    mDisplay.drawPixel(col * 16 + 7, row * 16 + 11, color == Color::BLACK ? 0 : 1);

    mDisplay.drawPixel(col * 16 + 8, row * 16 + 4, color == Color::BLACK ? 0 : 1);
    mDisplay.drawPixel(col * 16 + 8, row * 16 + 11, color == Color::BLACK ? 0 : 1);

    mDisplay.drawPixel(col * 16 + 11, row * 16 + 9, color == Color::BLACK ? 0 : 1);
    mDisplay.drawPixel(col * 16 + 11, row * 16 + 8, color == Color::BLACK ? 0 : 1);
    mDisplay.drawPixel(col * 16 + 11, row * 16 + 7, color == Color::BLACK ? 0 : 1);
    mDisplay.drawPixel(col * 16 + 11, row * 16 + 6, color == Color::BLACK ? 0 : 1);

    mDisplay.drawPixel(col * 16 + 10, row * 16 + 5, color == Color::BLACK ? 0 : 1);
    mDisplay.drawPixel(col * 16 + 10, row * 16 + 6, color == Color::BLACK ? 0 : 1);
    mDisplay.drawPixel(col * 16 + 10, row * 16 + 9, color == Color::BLACK ? 0 : 1);
    mDisplay.drawPixel(col * 16 + 10, row * 16 + 10, color == Color::BLACK ? 0 : 1);

    mDisplay.drawPixel(col * 16 + 9, row * 16 + 4, color == Color::BLACK ? 0 : 1);
    mDisplay.drawPixel(col * 16 + 9, row * 16 + 5, color == Color::BLACK ? 0 : 1);
    mDisplay.drawPixel(col * 16 + 9, row * 16 + 10, color == Color::BLACK ? 0 : 1);
    mDisplay.drawPixel(col * 16 + 9, row * 16 + 11, color == Color::BLACK ? 0 : 1);
}

void ChessBoard::getBishopMoves(int8_t piecePos[], Color color) {
    int8_t directions[4][2] = {
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1}
    };

    for (uint8_t i = 0; i < 4; i++) {
        int8_t currPos[2];
        currPos[0] = piecePos[0] + directions[i][0];
        currPos[1] = piecePos[1] + directions[i][1];

        while (!(currPos[0] < 0 || currPos[0] >= 4 || currPos[1] < 0 || currPos[1] >= 5)) {
            Piece piece = mBoard[currPos[0]][currPos[1]];

            if (piece != Piece::EMPTY) {
                if (getPieceColor(piece) != color && piece != Piece::WHITE_KING && piece != Piece::BLACK_KING) {
                    mMoves[1][currPos[0]][currPos[1]] = 1;
                }

                break;
            }

            mMoves[1][currPos[0]][currPos[1]] = 1;

            currPos[0] += directions[i][0];
            currPos[1] += directions[i][1];
        }
    }
}

void ChessBoard::getKnightMoves(int8_t piecePos[], Color color) {
    int8_t directions[8][2] = {
        {-2, -1},
        {-2, 1},
        {-1, -2},
        {-1, 2},
        {1, -2},
        {1, 2},
        {2, -1},
        {2, 1}
    };

    for (uint8_t i = 0; i < 8; i++) {
        int8_t currPos[2];
        currPos[0] = piecePos[0] + directions[i][0];
        currPos[1] = piecePos[1] + directions[i][1];

        // check if position is out of bounds
        if (currPos[0] < 0 || currPos[0] >= 4 || currPos[1] < 0 || currPos[1] >= 5) {
            continue;
        }

        Piece piece = mBoard[currPos[0]][currPos[1]];

        if (piece == Piece::EMPTY || (getPieceColor(piece) != color && piece != Piece::WHITE_KING && piece != Piece::BLACK_KING)) {
            mMoves[2][currPos[0]][currPos[1]] = 1;
        }
    }
}

void ChessBoard::getRookMoves(int8_t piecePos[], Color color) {
    int8_t directions[4][2] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    for (uint8_t i = 0; i < 4; i++) {
        int8_t currPos[2];
        currPos[0] = piecePos[0] + directions[i][0];
        currPos[1] = piecePos[1] + directions[i][1];

        while (!(currPos[0] < 0 || currPos[0] >= 4 || currPos[1] < 0 || currPos[1] >= 5)) {
            Piece piece = mBoard[currPos[0]][currPos[1]];

            if (piece != Piece::EMPTY) {
                if (getPieceColor(piece) != color && piece != Piece::WHITE_KING && piece != Piece::BLACK_KING) {
                    mMoves[3][currPos[0]][currPos[1]] = 1;
                }

                break;
            }

            mMoves[3][currPos[0]][currPos[1]] = 1;

            currPos[0] += directions[i][0];
            currPos[1] += directions[i][1];
        }
    }
}

void ChessBoard::getKingMoves(int8_t piecePos[], Color color) {
    int8_t directions[8][2] = {
        {-1, 0},
        {-1, 1},
        {-1, -1},
        {0, -1},
        {0, 1},
        {1, 1},
        {1, -1},
        {1, 0}
    };

    for (uint8_t i = 0; i < 8; i++) {
        int8_t currPos[2];
        currPos[0] = piecePos[0] + directions[i][0];
        currPos[1] = piecePos[1] + directions[i][1];

        if (!(currPos[0] < 0 || currPos[0] >= 4 || currPos[1] < 0 || currPos[1] >= 5)) {
            Piece piece = mBoard[currPos[0]][currPos[1]];

            if ((piece != Piece::EMPTY && getPieceColor(piece) != color && piece != Piece::WHITE_KING && piece != Piece::BLACK_KING) || piece == Piece::EMPTY) {
                mMoves[4][currPos[0]][currPos[1]] = 1;
            }
        }
    }
}

uint8_t ChessBoard::validateMoves() {
    Piece boardCopy[4][5];
    Color playerColor = getPieceColor(mBoard[mSelectedPiecePos[0]][mSelectedPiecePos[1]]);
    uint8_t pieceIdx = getPieceIdx(mBoard[mSelectedPiecePos[0]][mSelectedPiecePos[1]]);

    uint8_t moveCount = 0;

    for (uint8_t i = 0; i < 4; i++) {
        for (uint8_t j = 0; j < 5; j++) {
            if (!mMoves[pieceIdx][i][j]) {
                continue;
            }

            // copy board
            for (uint8_t row = 0; row < 4; row++) {
                for (uint8_t col = 0; col < 5; col++) {
                    boardCopy[row][col] = mBoard[row][col];
                }
            }

            // make move
            boardCopy[i][j] = boardCopy[mSelectedPiecePos[0]][mSelectedPiecePos[1]];
            boardCopy[mSelectedPiecePos[0]][mSelectedPiecePos[1]] = Piece::EMPTY;

            if (isChecked(playerColor, boardCopy)) {
                mMoves[pieceIdx][i][j] = 0;
            } else {
                moveCount++;
            }
        }
    }

    return moveCount;
}

bool ChessBoard::isChecked(Color playerColor, Piece board[4][5]) {
    // find king position
    int8_t kingPos[2] = {};

    for (uint8_t row = 0; row < 4; row++) {
        for (uint8_t col = 0; col < 5; col++) {
            if ((board[row][col] == Piece::WHITE_KING && playerColor == Color::WHITE) ||
                (board[row][col] == Piece::BLACK_KING && playerColor == Color::BLACK)) {
                kingPos[0] = row;
                kingPos[1] = col;
                break;
            }
        }
    }

    for (uint8_t row = 0; row < 4; row++) {
        for (uint8_t col = 0; col < 5; col++) {
            Piece piece = board[row][col];

            if (piece == Piece::EMPTY) {
                continue;
            }

            if (getPieceColor(piece) == playerColor) {
                continue;
            }

            if (piece == Piece::WHITE_KING || piece == Piece::BLACK_KING) {
                int8_t distX = row - kingPos[0];

                if (distX < 0) {
                    distX *= -1;
                }

                int8_t distY = col - kingPos[1];

                if (distY < 0) {
                    distY *= -1;
                }

                if (distX <= 1 && distY <= 1) {
                    return true;
                }
            } else if (piece == Piece::WHITE_BISHOP || piece == Piece::BLACK_BISHOP) {
                int8_t distX = row - kingPos[0];
                int8_t distY = col - kingPos[1];

                if (distX != distY && distX != distY * -1) {
                    continue;
                }

                int8_t directionX = (distX > 0) ? -1 : 1;
                int8_t directionY = (distY > 0) ? -1 : 1;

                int8_t posX = row + directionX;
                int8_t posY = col + directionY;

                bool ok = true;

                while (board[posX][posY] != Piece::WHITE_KING && board[posX][posY] != Piece::BLACK_KING) {
                    if (board[posX][posY] != Piece::EMPTY) {
                        ok = false;
                        break;
                    }

                    posX += directionX;
                    posY += directionY;
                }

                if (ok) {
                    return true;
                }
            } else if (piece == Piece::WHITE_KNIGHT || piece == Piece::BLACK_KNIGHT) {
                if ((row == kingPos[0] - 2 && col == kingPos[1] - 1) ||
                    (row == kingPos[0] - 2 && col == kingPos[1] + 1) ||
                    (row == kingPos[0] - 1 && col == kingPos[1] - 2) ||
                    (row == kingPos[0] - 1 && col == kingPos[1] + 2) ||
                    (row == kingPos[0] + 1 && col == kingPos[1] - 2) ||
                    (row == kingPos[0] + 1 && col == kingPos[1] + 2) ||
                    (row == kingPos[0] + 2 && col == kingPos[1] - 1) ||
                    (row == kingPos[0] + 2 && col == kingPos[1] + 1)) {
                    return true;
                }
            } else if (piece == Piece::WHITE_ROOK || piece == Piece::BLACK_ROOK) {
                if (row == kingPos[0]) {
                    int8_t direction = (kingPos[1] - col > 0) ? -1 : 1;

                    int8_t posY = kingPos[1] + direction;
                    bool ok = true;

                    while (board[row][posY] != Piece::WHITE_ROOK && board[row][posY] != Piece::BLACK_ROOK) {
                        if (board[row][posY] != Piece::EMPTY) {
                            ok = false;
                            break;
                        }

                        posY += direction;
                    }

                    if (ok) {
                        return true;
                    }
                } else if (col == kingPos[1]) {
                    int8_t direction = (kingPos[0] - row > 0) ? -1 : 1;

                    int8_t posX = kingPos[0] + direction;
                    bool ok = true;

                    while (board[posX][col] != Piece::WHITE_ROOK && board[posX][col] != Piece::BLACK_ROOK) {
                        if (board[posX][col] != Piece::EMPTY) {
                            ok = false;
                            break;
                        }

                        posX += direction;
                    }

                    if (ok) {
                        return true;
                    }
                }
            } else if (piece == Piece::WHITE_PAWN) {
                if (col == kingPos[1] - 1 && (row == kingPos[0] - 1 || row == kingPos[0] + 1)) {
                    return true;
                }
            } else if (piece == Piece::BLACK_PAWN) {
                if (col == kingPos[1] + 1 && (row == kingPos[0] - 1 || row == kingPos[0] + 1)) {
                    return true;
                }
            }
        }
    }

    return false;
}

void ChessBoard::moveSelectedPiece(int8_t dest[]) {
    if (mBoard[mSelectedPiecePos[0]][mSelectedPiecePos[1]] == Piece::WHITE_PAWN) {
        mWhitePawnMoved = true;
    } else if (mBoard[mSelectedPiecePos[0]][mSelectedPiecePos[1]] == Piece::BLACK_PAWN) {
        mBlackPawnMoved = true;
    }

    Piece piece = mBoard[mSelectedPiecePos[0]][mSelectedPiecePos[1]];

    // pawn upgrade
    if ((piece == Piece::WHITE_PAWN && dest[1] == 4) ||
        (piece == Piece::BLACK_PAWN && dest[1] == 0)) {
        piece = (piece == Piece::WHITE_PAWN) ? Piece::WHITE_ROOK : Piece::BLACK_ROOK;
    }

    mBoard[dest[0]][dest[1]] = piece;
    mBoard[mSelectedPiecePos[0]][mSelectedPiecePos[1]] = Piece::EMPTY;
}

int8_t ChessBoard::getMoveCount() {
    int8_t count = 0;

    for (uint8_t i = 0; i < 4; i++) {
        for (uint8_t j = 0; j < 5; j++) {
            if (mMoves[i][j]) {
                count++;
            }
        }
    }

    return count;
}

uint8_t ChessBoard::selectPlayer(Color playerColor, int8_t selectionPos[]) {
    bool selectedPiece = false;

    // find player's pieces
    for (uint8_t row = 0; row < 4; row++) {
        for (uint8_t col = 0; col < 5; col++) {
            Piece piece = mBoard[row][col];
            mPieces[row][col] = 0;

            if (piece == Piece::EMPTY || getPieceColor(piece) != playerColor) {
                continue;
            }

            // update moves for found piece
            mSelectedPiecePos[0] = row;
            mSelectedPiecePos[1] = col;

            getPossibleMoves();
            uint8_t moveCount = validateMoves();

            if (moveCount && !selectedPiece) {
                selectionPos[0] = row;
                selectionPos[1] = col;

                selectedPiece = true;
            }

            if (moveCount) {
                mPieces[row][col] = 1;
            }
        }
    }

    // no possible moves (checkmate / draw)
    if (selectedPiece == false) {
        return 0;
    } else {
        return 1;
    }
}

uint8_t ChessBoard::getPieceIdx(Piece piece) {
    if (piece == Piece::WHITE_PAWN || piece == Piece::BLACK_PAWN) {
        return 0;
    }

    if (piece == Piece::WHITE_BISHOP || piece == Piece::BLACK_BISHOP) {
        return 1;
    }

    if (piece == Piece::WHITE_KNIGHT || piece == Piece::BLACK_KNIGHT) {
        return 2;
    }

    if (piece == Piece::WHITE_ROOK || piece == Piece::BLACK_ROOK) {
        return 3;
    }

    if (piece == Piece::WHITE_KING || piece == Piece::BLACK_KING) {
        return 4;
    }
}

bool ChessBoard::insufficientMaterial() {
    uint8_t whiteMaterial = 0;
    uint8_t blackMaterial = 0;

    for (uint8_t row = 0; row < 4; row++) {
        for (uint8_t col = 0; col < 5; col++) {
            Piece piece = mBoard[row][col];

            if (piece == Piece::EMPTY) {
                continue;
            }

            switch (piece) {
                case Piece::WHITE_PAWN:
                    whiteMaterial += 5;
                    break;

                case Piece::WHITE_BISHOP:
                    whiteMaterial += 3;
                    break;

                case Piece::WHITE_KNIGHT:
                    whiteMaterial += 3;
                    break;

                case Piece::WHITE_ROOK:
                    whiteMaterial += 5;
                    break;

                case Piece::BLACK_PAWN:
                    blackMaterial += 5;
                    break;

                case Piece::BLACK_BISHOP:
                    blackMaterial += 3;
                    break;

                case Piece::BLACK_KNIGHT:   
                    blackMaterial += 3;
                    break;

                case Piece::BLACK_ROOK:
                    blackMaterial += 5;
                    break;

                default:
                    break;
            }
        }
    }

    return (whiteMaterial <= 3 && blackMaterial <= 3);
}

