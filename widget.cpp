#include "widget.h"
#include "ui_widget.h"
#include <tank.h>
#include <QPainter>
#include <QTimer>
#include <QMessageBox>
#include <QDebug>
#include <QList>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    Tank = new tank(width(), height());
    connect(&timer, SIGNAL(timeout()), this, SLOT(moveAll()));
    timer.start(100);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    Tank->draw(painter);
    if(shot) {
        qDebug()<<"aa"<<s;
        for (iter = shell.begin(); iter != shell.end(); iter++)
        iter->draw(painter);
    }
}

void Widget::keyPressEvent(QKeyEvent *k)
{
    if(k->key() == Qt::Key_W) {
        Tank->move(width(), height(), k->key());
        s = 1;
    }
    if(k->key() == Qt::Key_A) {
        Tank->move(width(), height(), k->key());
        s = 2;
    }
    if(k->key() == Qt::Key_S) {
        Tank->move(width(), height(), k->key());
        s = 3;
    }
    if(k->key() == Qt::Key_D) {
        Tank->move(width(), height(), k->key());
        s = 4;
    }
    if(k->key() == Qt::Key_Space) {
        qDebug()<<"bb";
        shells bullet(Tank->get_Point(), s);
        shell.push_back(bullet);
        shot = true;
    }
}

void Widget::moveAll()
{
    if(shot)
    {
        for (iter = shell.begin(); iter != shell.end(); iter++)
        {
            if(!iter->move(width(),height())) {
                iter = shell.erase(iter);
                qDebug()<<"erase";
                if(shell.empty()) shot = false;
                break;
            }
        }
    }
    this->repaint();
}


