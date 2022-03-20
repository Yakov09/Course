#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece
{
    bool movedAlready = false;
public:
    Rook(Chessfield *myF, bool myC);
    void setMovedAlready(bool moved);
    bool getMovedAlready();    
    bool* possiableMoves(Chessboard* board);
};

#endif // ROOK_H
