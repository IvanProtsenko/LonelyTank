#include "tank.h"

tank::tank(int w, int h)
{
    r = 25;
    vx = 10;
    vy = 10;
    point.setX(r + rand()%(w - 2*r));
    point.setY(r + rand()%(h - 2*r));
}

void tank::draw(QPainter &painter)
{
    painter.drawImage(point.x(), point.y(), QImage(":/images/images/tank.png").scaled(2*r, 2*r));
}

void tank::move(int w, int h, int key)
{
    if(key == Qt::Key_W) {
        point -= QPoint(0, vy);
    }
    if(key == Qt::Key_A) {
        point -= QPoint(vx, 0);
    }
    if(key == Qt::Key_S) {
        point += QPoint(0, vy);
    }
    if(key == Qt::Key_D) {
        point += QPoint(vx, 0);
    }

    if(point.x() + 2*r >= w) {
        point -= QPoint(vx, 0);
    }
    if(point.y() + 2*r >= h) {
        point -= QPoint(0, vy);
    }
    if(point.x() <= 0) {
        point += QPoint(vx, 0);
    }
    if(point.y() <= 0) {
        point += QPoint(0, vy);
    }
}

QPoint tank::get_Point() {
    return point;
}

