#include "test_bishop.h"
#include <QTest>

test_bishop::test_bishop(QObject *parent) : QObject(parent)
{

}

void test_bishop::possiableMoves(){
    Chessboard* testChessboard = new Chessboard;
    testChessboard->setTestPos_1();
    testPiece = testChessboard->getPieceFromField(2);
    if(testPiece == nullptr) return;
    int testAvMoves[64];
    int posMoves[64];
    int difAvMoves = 0;
    for(int i=0; i<64; ++i) testAvMoves[i] = 0;
    testAvMoves[9] = 1; testAvMoves[11] = 1; testAvMoves[16] = 1; testAvMoves[20] = 1;
    testAvMoves[29] = 2;
    testPiece->possiableMoves(testChessboard);
    testPiece->getPosMoves(posMoves);
    for(int i=0; i<64; ++i) if(posMoves[i] != testAvMoves[i]) difAvMoves++;
    QCOMPARE(difAvMoves, 0);

    testChessboard->setTestPos_2();
    testPiece = testChessboard->getPieceFromField(25);
    if(testPiece == nullptr) return;
    for(int i=0; i<64; ++i) testAvMoves[i] = 0;
    testAvMoves[16] = 1; testAvMoves[18] = 1; testAvMoves[32] = 2; testAvMoves[34] = 1;
    testAvMoves[43] = 1; testAvMoves[52] = 2;
    difAvMoves = 0;
    testPiece->possiableMoves(testChessboard);
    testPiece->getPosMoves(posMoves);
    for(int i=0; i<64; ++i) if(posMoves[i] != testAvMoves[i]) difAvMoves++;
    QCOMPARE(difAvMoves, 0);
}
