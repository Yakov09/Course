#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
public:
    Pawn();
    bool isMovePossiable(Chessfield *destPosition, bool takes);
};

#endif // PAWN_H
