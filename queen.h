#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece
{
public:
    Queen(Chessfield *myF, bool myC);
    int* possiableMoves(Chessboard* board);
};

#endif // QUEEN_H
