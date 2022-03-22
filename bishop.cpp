#include "bishop.h"

Bishop::Bishop(Chessfield *myF, bool myC)
{
    myField = myF;
    color = myC;
    whiteImageName = "bishop_w.png";
    blackImageName = "bishop_b.png";
}

int* Bishop::possiableMoves(Chessboard *board){

}
