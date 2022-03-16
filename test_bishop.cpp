#include "test_bishop.h"
#include <QTest>

test_bishop::test_bishop(QObject *parent) : QObject(parent)
{

}

void test_bishop::possiableMoves(){
    QCOMPARE(1, 1);
    QCOMPARE(1, 2);
}
