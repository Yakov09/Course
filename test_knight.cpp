#include "test_knight.h"
#include <QTest>

test_knight::test_knight(QObject *parent) : QObject(parent)
{

}
 void test_knight::possiableMoves(){
     Chessboard* testChessboard = new Chessboard;
     testChessboard->setTestPos_1();
     testPiece = testChessboard->getPieceFromField(0);
     if(testPiece == nullptr) return;
     int testAvMoves[64];
     int posMoves[64];
     int difAvMoves = 0;
 //    for(int i=0; i<64; ++i) testAvMoves[i] = 0;
 //    testAvMoves[8] = 1; testAvMoves[16] = 1; testAvMoves[24] = 1;
 //    testAvMoves[32] = 1; testAvMoves[40] = 1; testAvMoves[48] = 1; testAvMoves[56] = 1;
 //    testPiece->possiableMoves(testChessboard);
 //    testPiece->getPosMoves(posMoves);
 //    for(int i=0; i<64; ++i) if(posMoves[i] != testAvMoves[i]) difAvMoves++;
 //    QCOMPARE(difAvMoves, 0);

     testChessboard->setTestPos_2();
     testPiece = testChessboard->getPieceFromField(26);
     if(testPiece == nullptr) return;
     for(int i=0; i<64; ++i) testAvMoves[i] = 0;
     testAvMoves[16] = 1; testAvMoves[20] = 1; testAvMoves[32] = 2; testAvMoves[36] = 1;
     testAvMoves[41] = 1; testAvMoves[43] = 1;
     difAvMoves = 0;
     testPiece->possiableMoves(testChessboard);
     testPiece->getPosMoves(posMoves);
     for(int i=0; i<64; ++i) if(posMoves[i] != testAvMoves[i]) difAvMoves++;
     QCOMPARE(difAvMoves, 0);
 }
