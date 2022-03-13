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

    this->setMinimumHeight(size*8 + padding*2);
    this->setMinimumWidth(size*8 + padding*2);

    scene = new QGraphicsScene();   // Инициализируем сцену для отрисовки
    this->setScene(scene);          // Устанавливаем сцену в виджет

    myBoard = new Chessboard;
//    QGraphicsPixmapItem *pm[64];
//    for(int i=0; i<64; ++i) pm[i] = nullptr;
    myBoard->setInintPosition();
    drawBoard();
}

void MyGraphicsView::drawBoard(){
    scene->setSceneRect(0, 0, size*8 + padding*2, size*8 + padding*2);
    for(int i=0; i<64; ++i){
        QBrush color = (myBoard->getFieldColor(i) == 0) ?  Qt::gray : Qt::white;
        drawField(i, color);
        drawPiece(i);
    }
}

void MyGraphicsView::drawField(int fieldNum, QBrush color){
    QPen penBlack(Qt::black);
    int left = padding + (fieldNum % 8)*size;
    int top = padding + (7 - fieldNum/8)*size;
    QRect fieldRect(left, top, size, size);
    scene->addRect(fieldRect, penBlack, color);
}

void MyGraphicsView::drawPiece(int fieldNum){
    Piece* tempPiece = myBoard->getPieceFromField(fieldNum);
    QGraphicsPixmapItem *pm;
    if(tempPiece != nullptr){
        QString path = QString::fromStdString(tempPiece->getImagePath());
        QPixmap pieceImage(path);
        pm = scene->addPixmap(pieceImage);
        int left = padding + (fieldNum % 8)*size;
        int top = padding + (7 - fieldNum/8)*size;
        pm->setPos(left, top);
    }
}

void MyGraphicsView::mousePressEvent(QMouseEvent *mouseEvent){
    QPoint point = mouseEvent->pos();
    if((point.rx() < padding)||(point.rx() > padding + size * 8)||(point.ry() < padding)||(point.ry() > padding + size * 8)) return;
    int field_h = (point.rx() - padding) / size;
    int field_v = 7 - ((point.ry() - padding) / size);
    int field = field_h + field_v*8;
    std::cout << "\n -- Pressed field " << field << " --- ";
}



void MyGraphicsView::mouseReleaseEvent(QMouseEvent *mouseEvent){
    QPoint point = mouseEvent->pos();
    if((point.rx() < padding)||(point.rx() > padding + size * 8)||(point.ry() < padding)||(point.ry() > padding + size * 8)) return;
    int field_h = (point.rx() - padding) / size;
    int field_v = 7 - ((point.ry() - padding) / size);
    int field = field_h + field_v*8;
    std::cout << "\n -- Released field " << field << " --- ";
    if(myBoard->getPieceFromField(field) == nullptr) return;
    drawBoard();
    drawField(field, Qt::yellow);
    drawPiece(field);
    int posMoves[64];
    myBoard->getPieceFromField(field)->possiableMoves(myBoard);
    myBoard->getPieceFromField(field)->getPosMoves(posMoves);

    for(int i=0; i<64; ++i){
        if(posMoves[i] == 1){
            drawField(i, Qt::blue);
            drawPiece(i);
        }
        if(posMoves[i] == 2){
            drawField(i, Qt::red);
            drawPiece(i);
        }
    }

    std::cout << "\n My position: " << field << "\n";
    for(int i=7; i>=0; --i){
        for(int j=0; j<8; ++j){
            std::cout << posMoves[i*8 + j] << " ";
        }
        std::cout << "\n";
    }
}
