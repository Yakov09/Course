#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece
{
public:
    Bishop();    
    bool* possiableMoves(Chessboard* board);
};

#endif // BISHOP_H
