#include "mygraphicsview.h"

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

    drawBoard(scene, size, padding);
}

void MyGraphicsView::drawBoard(QGraphicsScene* boardScene, int size, int padding){

    boardScene->setSceneRect(0,0, size*8 + padding*2, size*8 + padding*2);
    for(int i=0; i<8; ++i)
        for(int j=0; j<8; ++j){
            drawField(size, size*i + padding, size*j + padding, (i+j)%2, boardScene);
        }
}

void MyGraphicsView::drawField(int size, int left, int top, int color, QGraphicsScene* boardScene){
    QPen penBlack(Qt::black);
    QBrush brush(color == 0 ? Qt::white : Qt::gray);
    QRect fieldRect(left, top, size, size);
    boardScene->addRect(fieldRect, penBlack, brush);
}


