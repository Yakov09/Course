#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
public:
    Pawn();    
    bool* possiableMoves(Chessboard* board);
};

#endif // PAWN_H
