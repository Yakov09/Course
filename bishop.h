#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece
{
public:
    Bishop(Chessfield *myF, bool myC);
    int* possiableMoves(Chessboard* board);
};

#endif // BISHOP_H
