#ifndef TEST_CHESSBOARD_H
#define TEST_CHESSBOARD_H

#include <QObject>
#include "chessboard.h"

class test_chessboard : public QObject
{
    Q_OBJECT
    Chessboard* testChessboard = nullptr;

public:
    explicit test_chessboard(QObject *parent = nullptr);

signals:
private slots:
    void clearBoard();
    void setInintPosition();
    void getPieceFromField();   
    void deletePiece();
};

#endif // TEST_CHESSBOARD_H
