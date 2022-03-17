#include "test_chessboard.h"
#include <QTest>


test_chessboard::test_chessboard(QObject *parent) : QObject(parent)
{
    testChessboard = new Chessboard;
}



void  test_chessboard::clearBoard(){
    testChessboard->setTestPos_1();
    testChessboard->clearBoard();
    int foundedPieces = 0;
    for(int i=0; i<64; ++i){
        if(testChessboard->getPieceFromField(i) != nullptr) foundedPieces++;
    }
    QCOMPARE(foundedPieces, 0);
    testChessboard->setTestPos_2();
    testChessboard->clearBoard();
    foundedPieces = 0;
    for(int i=0; i<64; ++i){
        if(testChessboard->getPieceFromField(i) != nullptr) foundedPieces++;
    }
    QCOMPARE(foundedPieces, 0);
}
void  test_chessboard::setInintPosition(){
    testChessboard->setInintPosition();
    int wrongFieldEmptiness = 0;
    for(int i=0; i<16; ++i) if(testChessboard->getPieceFromField(i)==nullptr) wrongFieldEmptiness++;
    for(int i=16; i<48; ++i) if(testChessboard->getPieceFromField(i)!=nullptr) wrongFieldEmptiness++;
    for(int i=48; i<64; ++i) if(testChessboard->getPieceFromField(i)==nullptr) wrongFieldEmptiness++;
    QCOMPARE(wrongFieldEmptiness, 0);
}

void test_chessboard::getPieceFromField(){
    testChessboard->setInintPosition();
    Piece* Piece_6 = testChessboard->getPieceFromField(6);
    testChessboard->clearBoard();
    bool PieceToNull = (Piece_6 != nullptr)&&(testChessboard->getPieceFromField(6) == nullptr);
    QCOMPARE(PieceToNull, true);
}

void test_chessboard::deletePiece(){
    testChessboard->setInintPosition();
    testChessboard->deletePiece(3);
    QCOMPARE(testChessboard->getPieceFromField(3), nullptr);
}
