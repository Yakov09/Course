#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>


class MyGraphicsView : public QGraphicsView
{
public:
    MyGraphicsView(QWidget *parent);

private:
    QGraphicsScene *scene;
    QGraphicsItemGroup *group_1;
    void drawField(int size, int left, int top, int color, QGraphicsScene* boardScene);
    void drawBoard(QGraphicsScene* boardScene, int size, int padding);
};

#endif // MYGRAPHICSVIEW_H
