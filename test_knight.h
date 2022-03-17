#ifndef TEST_KNIGHT_H
#define TEST_KNIGHT_H

#include <QObject>
#include "chessboard.h"
#include "knight.h"

class test_knight : public QObject
{
    Q_OBJECT
    Piece* testPiece = nullptr;
public:
    explicit test_knight(QObject *parent = nullptr);

signals:
private slots:
    void possiableMoves();
};

#endif // TEST_KNIGHT_H
