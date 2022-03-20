#ifndef PIECE_H
#define PIECE_H
#include "chessfield.h"

class Chessboard;
class Piece
{
protected:
    bool canJump = false;
    bool posMoves[64];
    bool moveMatrix[15][15];
public:
    Piece();
    //virtual bool isMovePossiable(Chessfield *destPosition, bool takes) = 0;  // doesn`t count attacked fields for king`s moves
    virtual bool* possiableMoves(Chessboard* board) = 0;
    void setPosMovesFalse();
};

#endif // PIECE_H
