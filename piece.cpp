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

Chessfield* Piece::getMyField(){
    return myField;
}
std::string Piece::getImagePath(){
    std::string actualImage = (color == 0) ? whiteImageName : blackImageName;
    return path + "/" + actualImage;
}
