#include "pawn.h"

Pawn::Pawn(Chessfield *myF, bool myC)
{
    myField = myF;
    color = myC;
    whiteImageName = "pawn_w.png";
    blackImageName = "pawn_b.png";
}

int* Pawn::possiableMoves(Chessboard *board){

}
