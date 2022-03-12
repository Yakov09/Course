#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece
{
    bool movedAlready;
public:
    Rook();
    void setMovedAlready(bool moved);
    bool getMovedAlready();
    bool isMovePossiable(Chessfield *destPosition, bool takes);
};

#endif // ROOK_H
