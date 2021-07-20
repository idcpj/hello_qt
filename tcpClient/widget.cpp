#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    tcpSocket = new QTcpSocket();

    connect(tcpSocket,&QTcpSocket::readyRead,this,&Widget::readMessage);
    connect(tcpSocket,SIGNAL(error),this,SLOT(displayError));



}

Widget::~Widget()
{
    delete ui;
}

void Widget::newConnect()
{
    QString  host=ui->hostLineEdit->text();
    QString port = ui->portLikneEdit->text();

    tcpSocket->connectToHost(host,quint16(port.toInt()));
}

void Widget::readMessage()
{

    ui->messageLabel->setText(tcpSocket->readAll());
}

void Widget::displayError(QAbstractSocket::SocketError err)
{
    qDebug()<<err;
}


void Widget::on_pushButton_clicked()
{
    newConnect();
}
