#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece
{
public:
    Knight();
    bool isMovePossiable(Chessfield *destPosition, bool takes);
};

#endif // KNIGHT_H
