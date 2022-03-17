#include "test_rook.h"
#include <QTest>

test_rook::test_rook(QObject *parent) : QObject(parent)
{

}

void test_rook::possiableMoves(){
    Chessboard* testChessboard = new Chessboard;
    testChessboard->setTestPos_1();
    testPiece = testChessboard->getPieceFromField(0);
    if(testPiece == nullptr) return;
    int testAvMoves[64];
    int posMoves[64];
    for(int i=0; i<64; ++i) testAvMoves[i] = 0;
    testAvMoves[8] = 1; testAvMoves[16] = 1; testAvMoves[24] = 2;
    int difAvMoves = 0;
    testPiece->possiableMoves(testChessboard);
    testPiece->getPosMoves(posMoves);
    for(int i=0; i<64; ++i) if(posMoves[i] != testAvMoves[i]) difAvMoves++;
    QCOMPARE(difAvMoves, 0);

    testChessboard->setTestPos_2();
    testPiece = testChessboard->getPieceFromField(27);
    if(testPiece == nullptr) return;
    for(int i=0; i<64; ++i) testAvMoves[i] = 0;
    testAvMoves[28] = 1; testAvMoves[29] = 1; testAvMoves[30] = 1; testAvMoves[31] = 2;
    testAvMoves[35] = 1; testAvMoves[43] = 1; testAvMoves[51] = 2; testAvMoves[19] = 1;
    difAvMoves = 0;
    testPiece->possiableMoves(testChessboard);
    testPiece->getPosMoves(posMoves);
    for(int i=0; i<64; ++i) if(posMoves[i] != testAvMoves[i]) difAvMoves++;
    QCOMPARE(difAvMoves, 0);
}
