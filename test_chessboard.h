#ifndef TEST_CHESSBOARD_H
#define TEST_CHESSBOARD_H

#include <QObject>
#include "chessboard.h"

class test_chessboard : public QObject
{
    Q_OBJECT
public:
    explicit test_chessboard(QObject *parent = nullptr);

signals:
private slots:
    void setInintPosition();
    void getPieceFromField();
    void transformPiece();
    void deletePiece();
};

#endif // TEST_CHESSBOARD_H
