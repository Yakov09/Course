#include "test_queen.h"
#include <QTest>

test_queen::test_queen(QObject *parent) : QObject(parent)
{

}

void test_queen::possiableMoves(){
    Chessboard* testChessboard = new Chessboard;
    testChessboard->setTestPos_1();
    testPiece = testChessboard->getPieceFromField(3);
    if(testPiece == nullptr) return;
    int testAvMoves[64];
    int posMoves[64];
    int difAvMoves = 0;
    for(int i=0; i<64; ++i) testAvMoves[i] = 0;
    testAvMoves[10] = 1; testAvMoves[11] = 1; testAvMoves[12] = 1; testAvMoves[17] = 1;
    testAvMoves[19] = 1; testAvMoves[21] = 1; testAvMoves[24] = 2; testAvMoves[27] = 2;
    testAvMoves[30] = 1; testAvMoves[39] = 1;
    testPiece->possiableMoves(testChessboard);
    testPiece->getPosMoves(posMoves);
    for(int i=0; i<64; ++i) if(posMoves[i] != testAvMoves[i]) difAvMoves++;
    QCOMPARE(difAvMoves, 0);

    testChessboard->setTestPos_2();
    testPiece = testChessboard->getPieceFromField(23);
    if(testPiece == nullptr) return;
    for(int i=0; i<64; ++i) testAvMoves[i] = 0;
    testAvMoves[22] = 1; testAvMoves[21] = 1; testAvMoves[20] = 1; testAvMoves[19] = 1;
    testAvMoves[18] = 1; testAvMoves[17] = 1; testAvMoves[16] = 1; testAvMoves[30] = 1;
    testAvMoves[31] = 2; testAvMoves[37] = 1; testAvMoves[44] = 1; testAvMoves[51] = 2;
    difAvMoves = 0;
    testPiece->possiableMoves(testChessboard);
    testPiece->getPosMoves(posMoves);
    for(int i=0; i<64; ++i) if(posMoves[i] != testAvMoves[i]) difAvMoves++;
    QCOMPARE(difAvMoves, 0);
}
