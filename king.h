#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
    bool movedAlready;
public:
    King();
    void setMovedAlready(bool moved);
    bool getMovedAlready();
    bool isMovePossiable(Chessfield *destPosition, bool takes);
};

#endif // KING_H
