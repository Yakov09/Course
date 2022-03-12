#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece
{
public:
    Queen(Chessfield *myF, bool myC);
    bool* possiableMoves(Chessboard* board);
};

#endif // QUEEN_H
