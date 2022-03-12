#include "chessboard.h"

Chessboard::Chessboard()
{
    for(int i=0; i<64; ++i){
        field[i] = new Chessfield(i, true, (i+1)%2);
    }
}
