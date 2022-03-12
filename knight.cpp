#include "knight.h"

Knight::Knight(Chessfield *myF, bool myC)
{
    myField = myF;
    color = myC;
    canJump = true;
    whiteImageName = "knight_w.png";
    blackImageName = "knight_b.png";
}

bool* Knight::possiableMoves(Chessboard *board){

}
