#include "chessboard.h"
#include <iostream>
Chessboard::Chessboard()
{
    for(int i=0; i<64; ++i){
        field[i] = new Chessfield(i, true, (i+i/8)%2);
    }
    for(int i=0; i<MAX_PIECES; ++i)
        placedPieces[i] = nullptr;
}
bool Chessboard::getFieldColor(int fieldNum){
    return field[fieldNum]->getColor();
}

int Chessboard::setPiece(Piece **pieceSlot, Piece *piecePlaced, Chessfield fieldPlaced){
    if(fieldPlaced.isEmpty() != true) return 1;
    *pieceSlot = piecePlaced;
    fieldPlaced.setEmpty(false);
    return 0;
}

void Chessboard::clearBoard(){
    for(int i=0; i<MAX_PIECES; ++i){
        deletePiece(i);
        placedPieces[i] = nullptr;
    }
}
void Chessboard::setInintPosition(){
    clearBoard();
    ;
    placedPieces[0] = new Rook(field[0], 0);
    placedPieces[1] = new Knight(field[1], 0);
    placedPieces[2] = new Bishop(field[2], 0);
    placedPieces[3] = new Queen(field[3], 0);
    placedPieces[4] = new King(field[4], 0);
    placedPieces[5] = new Bishop(field[5], 0);
    placedPieces[6] = new Knight(field[6], 0);
    placedPieces[7] = new Rook(field[7], 0);
    for(int i = 8;i<16;++i) placedPieces[i] = new Pawn(field[i], 0);
    for(int i = 16;i<24;++i) placedPieces[i] = new Pawn(field[i+32], 1);
    placedPieces[24] = new Rook(field[56], 1);
    placedPieces[25] = new Knight(field[57], 1);
    placedPieces[26] = new Bishop(field[58], 1);
    placedPieces[27] = new Queen(field[59], 1);
    placedPieces[28] = new King(field[60], 1);
    placedPieces[29] = new Bishop(field[61], 1);
    placedPieces[30] = new Knight(field[62], 1);
    placedPieces[31] = new Rook(field[63], 1);
}
void Chessboard::deletePiece(int slot){
    if((slot < 0)||(slot >= MAX_PIECES)) return;
    if(placedPieces[slot] != nullptr) placedPieces[slot]->~Piece();
    placedPieces[slot] = nullptr;
}
void Chessboard::deletePiece(Piece *delPiece){
    int slot = MAX_PIECES;
    for(int i=0; i<MAX_PIECES; ++i) if(placedPieces[i] == delPiece) slot = i;
    if(slot == MAX_PIECES) return;
    delPiece->~Piece();
    placedPieces[slot] = nullptr;
}

Piece* Chessboard::getPieceFromField(int aimField){
    for(int i=0; i<MAX_PIECES; ++i){
        if(placedPieces[i] == nullptr) continue;
        if(placedPieces[i]->getMyField() == field[aimField]) return placedPieces[i];
    }
    return nullptr;
}
bool Chessboard::isChosenPiece(){ return PieceChosen;}

void Chessboard::setChosenPiece(bool status, Piece* actPiece = nullptr){
    activePiece = actPiece;
    if(!status) activePiece = nullptr;
    PieceChosen = status;
}

Piece* Chessboard::getChosenPiece(){
    return activePiece;
}

void Chessboard::setMoveOrder(bool order){moveOrder = order;}

bool Chessboard::getMoveOrder(){return moveOrder;}

Chessfield* Chessboard::getField(int fieldNum){
    if((fieldNum < 0)||(fieldNum > 63)) return nullptr;
    return field[fieldNum];
}
