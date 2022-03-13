#include "king.h"

King::King(Chessfield *myF, bool myC)
{
    myField = myF;
    color = myC;
    whiteImageName = "king_w.png";
    blackImageName = "king_b.png";
    range = 1;
}

void King::possiableMoves(Chessboard *board){
    setPosMovesFalse();
    hvCheck(board);
    diaCheck(board);
}
