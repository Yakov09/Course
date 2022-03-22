#include "king.h"

King::King(Chessfield *myF, bool myC)
{
    myField = myF;
    color = myC;
    whiteImageName = "king_w.png";
    blackImageName = "king_b.png";
}

int* King::possiableMoves(Chessboard *board){

}
