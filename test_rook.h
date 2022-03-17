#ifndef TEST_ROOK_H
#define TEST_ROOK_H

#include <QObject>
#include "chessboard.h"
#include "rook.h"

class test_rook : public QObject
{
    Q_OBJECT
    Piece* testPiece = nullptr;
public:
    explicit test_rook(QObject *parent = nullptr);

signals:
private slots:
    void possiableMoves();
};

#endif // TEST_ROOK_H
