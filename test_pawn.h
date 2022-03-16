#ifndef TEST_PAWN_H
#define TEST_PAWN_H

#include <QObject>
#include "chessboard.h"
#include "pawn.h"

class test_pawn : public QObject
{
    Q_OBJECT
public:
    explicit test_pawn(QObject *parent = nullptr);

signals:
private slots:
    void possiableMoves();
};

#endif // TEST_PAWN_H
