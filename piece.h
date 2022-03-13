#ifndef PIECE_H
#define PIECE_H
#include "chessfield.h"
#include <string>

class Chessboard;
class Piece
{
protected:
    std::string path = "/home/yakov/Chess001/images";
    std::string whiteImageName = "";
    std::string blackImageName = "";
    bool color;                                                 // 0 - white, 1 - black
    Chessfield* myField;
    bool canJump = false;
    bool posMoves[64];
    bool moveMatrix[15][15];
public:
    Piece();    
    virtual int* possiableMoves(Chessboard* board) = 0;   // 0 - no move, 1 - can move, 2 - can take
    void setPosMovesFalse();
    Chessfield* getMyField();
    std::string getImagePath();

};

#endif // PIECE_H
