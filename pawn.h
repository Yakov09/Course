#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
public:
    Pawn(Chessfield *myF, bool myC);
    bool* possiableMoves(Chessboard* board);
};

#endif // PAWN_H
