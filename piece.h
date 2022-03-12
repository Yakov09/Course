#ifndef PIECE_H
#define PIECE_H
#include "chessfield.h"


class Piece
{
    Chessfield *curPosition;
public:
    Piece();
    virtual bool isMovePossiable(Chessfield *destPosition, bool takes) = 0;  // doesn`t count attacked fields for king`s moves
};

#endif // PIECE_H
