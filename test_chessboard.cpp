#include "test_chessboard.h"
#include <QTest>


test_chessboard::test_chessboard(QObject *parent) : QObject(parent)
{

}

void  test_chessboard::setInintPosition(){
    QCOMPARE(1, 1);
}

void test_chessboard::getPieceFromField(){
    QCOMPARE(1, 1);
}

void test_chessboard::transformPiece(){
    QCOMPARE(1, 1);
}

void test_chessboard::deletePiece(){
    QCOMPARE(1, 1);
}
