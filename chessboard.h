#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "chessfield.h"
#include "piece.h"

class Chessboard
{
    Chessfield *field[64];
    bool moveOrder; // 0 - white, 1 - black
    Chessfield *possiableMoves[][2]; // field[from,to]
public:
    Chessboard();
    int makeMove(Chessfield fieldNow, Chessfield fieldDest);  // 0 - Ok, 1 - no figure to move, 2 - incorrect move, 3 - other failes
    int setPiece(Piece* piecePlaced, Chessfield fieldPlaced);  // 0 - Ok, 1 - field is not empty, 2 - other fails
    void clearBoard();
    void setInintPosition();
    void setMoveOrder(bool order);
    bool getMoveOrder();
    ~Chessboard();

    bool isBlackCK();   // CK - castle kingside
    bool isBlackCQ();   // CQ - castle queenside
    bool isWhiteCK();
    bool isWhiteCQ();
};

#endif // CHESSBOARD_H
