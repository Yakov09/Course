#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView(QWidget *parent)
    :QGraphicsView(parent)
{
    /* Немного поднастроим отображение виджета и его содержимого */
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
    this->setAlignment(Qt::AlignCenter);                        // Делаем привязку содержимого к центру
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету

    /* Также зададим минимальные размеры виджета
     * */
    this->setMinimumHeight(100);
    this->setMinimumWidth(100);

    scene = new QGraphicsScene();   // Инициализируем сцену для отрисовки
    this->setScene(scene);          // Устанавливаем сцену в виджет

    group_1 = new QGraphicsItemGroup();

    int width = this->width();      // определяем ширину нашего виджета
    int height = this->height();    // определяем высоту нашего виджета

    /* Устанавливаем размер сцены по размеру виджета
     * Первая координата - это левый верхний угол,
     * а Вторая - это правый нижний угол
     * */
    scene->setSceneRect(0,0,width,height);
    QPen penBlack(Qt::black); // Задаём чёрную кисть
    /* Нарисуем черный прямоугольник
     * */
    group_1->addToGroup(scene->addLine(20,20, width - 20, 20, penBlack));
    group_1->addToGroup(scene->addLine(width - 20, 20, width - 20, height -20, penBlack));
    group_1->addToGroup(scene->addLine(width - 20, height -20, 20, height -20, penBlack));
    group_1->addToGroup(scene->addLine(20, height -20, 20, 20, penBlack));

    scene->addItem(group_1);
}
