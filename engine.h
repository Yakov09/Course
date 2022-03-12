#ifndef ENGINE_H
#define ENGINE_H
#include "chessboard.h"

class engine
{
public:
    engine();

    Chessboard *getMove(Chessboard* board);
};

#endif // ENGINE_H
