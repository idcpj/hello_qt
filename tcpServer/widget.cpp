#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    tcpServer = new QTcpServer(this);
    if(!tcpServer->listen(QHostAddress::LocalHost,6666)){
        qDebug()<<tcpServer->errorString();
        close();
    }
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(sendMessage()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::sendMessage()
{
    //用于暂存我们要发送的数据
    QByteArray block;

    //使用数据流写入数据
    QDataStream out(&block,QIODevice::WriteOnly);

    //设置数据流的版本，客户端和服务器端使用的版本要相同
    out.setVersion(QDataStream::Qt_4_6);

    out<<quint16(0);
    out<<tr("hello Tcp!!!");
    out.device()->seek(0);
    out<< quint16(block.size()-quint16(sizeof(quint16)));

    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();

    qDebug()<<"kjbkj"<<clientConnection;




    connect(clientConnection, &QTcpSocket::disconnected, clientConnection, &QTcpSocket::deleteLater);


    clientConnection->write(block);
    clientConnection->disconnectFromHost();


    ui->statusLabel->setText("send message successfull");






}

