#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "chessfield.h"
#include "piece.h"
#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"

class Chessboard
{
    static const int MAX_PIECES = 32;
    Chessfield *field[64];
    Piece *placedPieces[MAX_PIECES];
    bool moveOrder; // 0 - white, 1 - black    
    bool BlackCK = true;
    bool BlackCQ = true;
    bool WhiteCK = true;
    bool WhiteCQ = true;
    bool PieceChosen = false;
    Piece* activePiece = nullptr;
public:
    Chessboard();
    int makeMove(Chessfield fieldNow, Chessfield fieldDest);  // 0 - Ok, 1 - no figure to move, 2 - incorrect move, 3 - other failes
    int setPiece(Piece** pieceSlot, Piece* piecePlaced, Chessfield fieldPlaced);  // 0 - Ok, 1 - field is not empty, 2 - other fails
    void deletePiece(int slot);
    void deletePiece(Piece* delPiece);

    void clearBoard();
    void setInintPosition();
    Piece* getPieceFromField(int aimField);
    void setMoveOrder(bool order);
    bool getMoveOrder();
    bool getFieldColor(int fieldNum);
    ~Chessboard();
    bool isChosenPiece();
    void setChosenPiece(bool status, Piece* actPiece);
    Piece* getChosenPiece();
    Chessfield* getField(int fieldNum);

    bool isBlackCK();   // CK - castle kingside
    bool isBlackCQ();   // CQ - castle queenside
    bool isWhiteCK();
    bool isWhiteCQ();
};

#endif // CHESSBOARD_H
