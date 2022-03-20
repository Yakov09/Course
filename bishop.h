#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece
{
public:
    Bishop(Chessfield *myF, bool myC);
    bool* possiableMoves(Chessboard* board);
};

#endif // BISHOP_H
