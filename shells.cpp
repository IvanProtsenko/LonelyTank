#include "shells.h"

shells::shells(QPoint ppoint, int ss)
{
    point = ppoint;
    r = 4;
    v = 15;
    s = ss;
}
bool shells::move(int w, int h)
{
    if(s == 1) {
        point -= QPoint(0, v);
    }
    if(s == 2) {
        point -= QPoint(v, 0);
    }
    if(s == 3) {
        point += QPoint(0, v);
    }
    if(s == 4) {
        point += QPoint(v, 0);
    }
    if(point.x() + r >= w) {
        return false;
    }
    if(point.y() + r >= h) {
        return false;
    }
    if(point.x() + r <= 0) {
        return false;
    }
    if(point.y() + r <= 0) {
        return false;
    }
    return true;
}

void shells::draw(QPainter &painter)
{
    painter.drawImage(point.x()+15, point.y()+15, QImage(":/images/images/Cannon_Ball.png").scaled(2*r, 2*r));
}

