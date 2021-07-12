#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    ui->pushButton->setText(tr("%1,%2")
                            .arg(e->x())
                            .arg(e->y()));
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    int x = ui->pushButton->x();
    int y = ui->pushButton->y();

    qDebug() << "event->key()"<<event->key();


    switch(event->key()){
        case Qt::Key_W:ui->pushButton->move(x,y-10);break;
        case Qt::Key_S:ui->pushButton->move(x,y+10);break;
        case Qt::Key_A:ui->pushButton->move(x-10,y);break;
        case Qt::Key_D:ui->pushButton->move(x+10,y);break;
    }

}


