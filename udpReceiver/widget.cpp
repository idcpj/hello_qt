#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    receiver=new QUdpSocket(this);
    receiver->bind(45454,QUdpSocket::ShareAddress);
    connect(receiver,SIGNAL(readyRead()),this,SLOT(processPendingDatagram()));


}

Widget::~Widget()
{
    delete ui;
}

void Widget::processPendingDatagram()
{

    while (receiver->hasPendingDatagrams()) {
        QByteArray data;
        data.resize(receiver->pendingDatagramSize());
        qDebug()<<"receiver:" <<receiver->readDatagram(data.data(),data.size());
        ui->label->setText(data);


    }
}

