#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
    bool movedAlready = false;
    bool checked = false;
public:
    King();
    void setMovedAlready(bool moved);
    bool getMovedAlready();    
    bool* possiableMoves(Chessboard* board);
};

#endif // KING_H
