#include "test_pawn.h"
#include <QTest>

test_pawn::test_pawn(QObject *parent) : QObject(parent)
{

}

void test_pawn::possiableMoves(){
    QCOMPARE(1, 1);
}
