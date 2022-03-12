#include "piece.h"

Piece::Piece()
{
    for(int i=0; i<15; ++i)
        for(int j=0; j<15; ++j)
            moveMatrix[i][j] = false;
    setPosMovesFalse();
}
void Piece::setPosMovesFalse(){
    for(int i=0; i<64; ++i) posMoves[i] = false;
}
