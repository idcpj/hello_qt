#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    resize(600,500);
    pix=QPixmap(200,200);
    pix.fill(Qt::white);

    scale=1;
    button = new QPushButton(this);
    button->setText(tr("zoomIn"));
    button->move(500,450);

    connect(button,&QPushButton::clicked,[this]{
        zoomIn();
    });



}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::zoomIn()
{
    scale*=2;
    update();

}

void Dialog::paintEvent(QPaintEvent *event)
{


    QPainter pp(&pix);
    int x1 = firstPoint.x();
    int y1 = firstPoint.y();
    int w = endPoint.x()-x1;
    int h =endPoint.y()-y1;
    qDebug()<<"x1,y1,w,h"<<x1<<y1<<w<<h;
    pp.drawRect(x1,y1,w,h);


    QPainter painter(this);
    painter.drawPixmap(0,0,pix);





}


void Dialog::mousePressEvent(QMouseEvent *event)
{
   if(event->button()==Qt::LeftButton) //鼠标左键按下
   firstPoint = event->pos();
}

void Dialog::mouseMoveEvent(QMouseEvent *event)
{
     if(event->buttons()&Qt::LeftButton) //鼠标左键按下的同时移动鼠标
    {
              endPoint = event->pos();
              update(); //进行绘制
     }
}


void Dialog::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) //鼠标左键释放
     {
              endPoint = event->pos();
              update();
     }
}
