#include "test_pawn.h"
#include <QTest>

test_pawn::test_pawn(QObject *parent) : QObject(parent)
{

}

void test_pawn::possiableMoves(){
    Chessboard* testChessboard = new Chessboard;
    testChessboard->setTestPos_1();
    testChessboard->setMoveOrder(!testChessboard->getMoveOrder());
    testPiece = testChessboard->getPieceFromField(26);
    if(testPiece == nullptr) return;
    int testAvMoves[64];
    int posMoves[64];
    int difAvMoves = 0;
    for(int i=0; i<64; ++i) testAvMoves[i] = 0;
    testAvMoves[18] = 1;
    testPiece->possiableMoves(testChessboard);
    testPiece->getPosMoves(posMoves);
    for(int i=0; i<64; ++i) if(posMoves[i] != testAvMoves[i]) difAvMoves++;
    QCOMPARE(difAvMoves, 0);

    testChessboard->setTestPos_2();
    testPiece = testChessboard->getPieceFromField(12);
    if(testPiece == nullptr) return;
    for(int i=0; i<64; ++i) testAvMoves[i] = 0;
    testAvMoves[20] = 1; testAvMoves[28] = 1;
    difAvMoves = 0;
    testPiece->possiableMoves(testChessboard);
    testPiece->getPosMoves(posMoves);
    for(int i=0; i<64; ++i) if(posMoves[i] != testAvMoves[i]) difAvMoves++;
    QCOMPARE(difAvMoves, 0);
}
