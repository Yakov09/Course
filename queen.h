#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece
{
public:
    Queen();
    bool isMovePossiable(Chessfield *destPosition, bool takes);
};

#endif // QUEEN_H
