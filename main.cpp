#include "mainwindow.h"

#include <QApplication>
#include <QTest>
#include "test_bishop.h"
#include "test_chessboard.h"
#include "test_king.h"
#include "test_knight.h"
#include "test_pawn.h"
#include "test_queen.h"
#include "test_rook.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    freopen("testing.log", "w", stdout);
    QTest::qExec(new test_bishop, argc, argv);
    QTest::qExec(new test_chessboard, argc, argv);
    QTest::qExec(new test_king, argc, argv);
    QTest::qExec(new test_knight, argc, argv);
    QTest::qExec(new test_pawn, argc, argv);
    QTest::qExec(new test_queen, argc, argv);
    QTest::qExec(new test_rook, argc, argv);
    return a.exec();
}
