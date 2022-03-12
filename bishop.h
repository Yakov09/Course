#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece
{
public:
    Bishop();
    bool isMovePossiable(Chessfield *destPosition, bool takes);
};

#endif // BISHOP_H
