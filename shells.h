#ifndef SHELLS_H
#define SHELLS_H

#include <QtGui>

class shells
{
private:
    int s, r, v;
    QPoint point;
public:
    shells(QPoint ppoint, int ss);
    bool move(int w, int h);
    void draw(QPainter& painter);
};
#endif
