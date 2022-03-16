#ifndef TEST_KING_H
#define TEST_KING_H

#include <QObject>
#include "chessboard.h"
#include "king.h"

class test_king : public QObject
{
    Q_OBJECT
public:
    explicit test_king(QObject *parent = nullptr);

signals:
private slots:
    void possiableMoves();
};

#endif // TEST_KING_H
