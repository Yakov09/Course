#include "test_king.h"
#include <QTest>

test_king::test_king(QObject *parent) : QObject(parent)
{

}

void test_king::possiableMoves(){
    Chessboard* testChessboard = new Chessboard;
    testChessboard->setTestPos_1();
    testPiece = testChessboard->getPieceFromField(4);
    if(testPiece == nullptr) return;
    int testAvMoves[64];
    int posMoves[64];
    int difAvMoves = 0;
    for(int i=0; i<64; ++i) testAvMoves[i] = 0;
    testAvMoves[5] = 1; testAvMoves[6] = 3; testAvMoves[11] = 1; testAvMoves[12] = 1;
    //testAvMoves[13] = 1;
    testPiece->possiableMoves(testChessboard);
    testPiece->getPosMoves(posMoves);
    for(int i=0; i<64; ++i) if(posMoves[i] != testAvMoves[i]) difAvMoves++;
    QCOMPARE(difAvMoves, 0);

    testChessboard->setTestPos_2();
    testChessboard->lockBlackCastle();
    testChessboard->lockWhiteCastle();
    testPiece = testChessboard->getPieceFromField(4);
    if(testPiece == nullptr) return;
    for(int i=0; i<64; ++i) testAvMoves[i] = 0;
    testAvMoves[3] = 1; testAvMoves[5] = 1;
    difAvMoves = 0;
    testPiece->possiableMoves(testChessboard);
    testPiece->getPosMoves(posMoves);
    for(int i=0; i<64; ++i) if(posMoves[i] != testAvMoves[i]) difAvMoves++;
    QCOMPARE(difAvMoves, 0);
}
