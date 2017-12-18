#ifndef TANK_H
#define TANK_H

#include <QtGui>
#include <QPainter>

class tank
{
protected:
    int vx, vy;
    int r;
    QPoint point;
public:
    tank(int w, int h);
    void move(int w, int h, int key);
    void draw(QPainter &painter);
    QPoint get_Point();
};

#endif // TANK_H
