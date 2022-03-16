#ifndef TEST_QUEEN_H
#define TEST_QUEEN_H

#include <QObject>
#include "queen.h"
#include "chessboard.h"

class test_queen : public QObject
{
    Q_OBJECT
public:
    explicit test_queen(QObject *parent = nullptr);

signals:
private slots:
    void possiableMoves();
};

#endif // TEST_QUEEN_H
