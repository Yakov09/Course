#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece
{
public:
    Knight();    
    bool* possiableMoves(Chessboard* board);
};

#endif // KNIGHT_H
