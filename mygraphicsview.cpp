#include "mygraphicsview.h"
#include <iostream>
MyGraphicsView::MyGraphicsView(QWidget *parent)
    :QGraphicsView(parent)
{
    /* Немного поднастроим отображение виджета и его содержимого */
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
    this->setAlignment(Qt::AlignCenter);                        // Делаем привязку содержимого к центру
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету

    /* Также зададим минимальные размеры виджета */
    int size = 50;
    int padding = 20;
    this->setMinimumHeight(size*8 + padding*2);
    this->setMinimumWidth(size*8 + padding*2);

    scene = new QGraphicsScene();   // Инициализируем сцену для отрисовки
    this->setScene(scene);          // Устанавливаем сцену в виджет


    Chessboard *myBoard = new Chessboard;
    myBoard->setInintPosition();
    drawBoard(scene, size, padding, myBoard);
   // char path[] = "/home/yakov/Chess001/images/king_w.png";
   // QPixmap imageKing(path);
    //QGraphicsPixmapItem *pm = scene->addPixmap(imageKing);

    //int a=7, b=5;

    //if(myBoard->getPieceFromField(0) != nullptr) a=3;
    //pm->setPos(size*a + padding,size*b + padding);
}

void MyGraphicsView::drawBoard(QGraphicsScene* boardScene, int size, int padding, Chessboard* board){

    boardScene->setSceneRect(0, 0, size*8 + padding*2, size*8 + padding*2);
    for(int i=0; i<8; ++i)
        for(int j=0; j<8; ++j){
            drawField(size, size*i + padding, size*j + padding, board->getFieldColor(i+j*8), boardScene);
        }

    for(int i=0; i<8; ++i)
        for(int j=0; j<8; ++j){
            Piece* tempPiece = board->getPieceFromField(i*8 + j);
            if(tempPiece != nullptr){
                std::cout << "\n --- " << tempPiece->getImagePath() << "---\n";
                QString path = QString::fromStdString(tempPiece->getImagePath());
                QPixmap pieceImage(path);
                QGraphicsPixmapItem *pm = scene->addPixmap(pieceImage);
                pm->setPos(size*(j) + padding, size*(7-i) + padding);
            }
        }
}

void MyGraphicsView::drawField(int size, int left, int top, int color, QGraphicsScene* boardScene){
    QPen penBlack(Qt::black);
    QBrush brush(color == 0 ? Qt::white : Qt::gray);
    QRect fieldRect(left, top, size, size);
    boardScene->addRect(fieldRect, penBlack, brush);
}


