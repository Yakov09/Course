#ifndef TEST_BISHOP_H
#define TEST_BISHOP_H


#include <QObject>
#include "bishop.h"
#include "chessboard.h"

class test_bishop : public QObject
{
    Q_OBJECT
    Piece* testPiece = nullptr;
public:
    explicit test_bishop(QObject *parent = nullptr);

signals:
private slots:
    void possiableMoves();
};

#endif // TEST_BISHOP_H
