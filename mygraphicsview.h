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

};

#endif // MYGRAPHICSVIEW_H
