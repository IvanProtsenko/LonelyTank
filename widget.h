#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "shells.h"
#include "tank.h"
#include <QTimer>
#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    QTimer timer;
    tank * Tank;
    QList <shells> shell;
    QList <shells>::iterator iter;

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
protected:
    void keyPressEvent(QKeyEvent * k);
    void paintEvent(QPaintEvent * e);
protected slots:
    void moveAll();
private:
    Ui::Widget *ui;
    bool shot = false;
    int s = 0;
};

#endif // WIDGET_H
