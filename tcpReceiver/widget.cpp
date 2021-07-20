#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    tcpServer=new QTcpServer();

    totalBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;
    connect(tcpServer,&QTcpServer::newConnection,this,&Widget::acceptConnetion);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::start()
{
    ui->startButton->setEnabled(false);

    bytesReceived=0;
    if(!tcpServer->listen(QHostAddress::LocalHost,8080)){
        qDebug()<<tcpServer->errorString();
//        close();
        return;
    }

    ui->serverStatusLabel->setText(tr("监听"));

}

void Widget::acceptConnetion()
{
    tcpClient =tcpServer->nextPendingConnection();
    connect(tcpClient,&QTcpSocket::readyRead,this,&Widget::updateServrProgress);
    connect(tcpClient,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));

    ui->serverStatusLabel->setText(tr("接受连接"));
    tcpServer->close(); //?
}


void Widget::updateServrProgress()
{
    QDataStream in(tcpClient);

    //如果接收到的数据小于16个字节，那么是刚开始接收数据，我们保存到//来的头文件信息
    if(bytesReceived <= qint64(sizeof(qint64)*2)){
        if(tcpClient->bytesAvailable()>=qint64(sizeof(qint64)*2) &&
                fileNameSize==0){
            in>>totalBytes>>fileNameSize;
            bytesReceived+=qint64(sizeof(qint64)*2);
        }
        qDebug()<<"fileNameSize:"<<fileNameSize;

        if(tcpClient->bytesAvailable()>=fileNameSize &&
                fileNameSize !=0){
            in>>fileName;
            qDebug()<<"fileName:"<<fileName;

            ui->serverStatusLabel->setText(tr("接受文件 %1").arg(fileName));
            bytesReceived+=fileNameSize;

            localFile= new QFile(fileName);
            if(!localFile->open(QIODevice::WriteOnly)){
                qDebug()<< localFile->errorString();
                return;
            }
        }
    }

    if(bytesReceived<totalBytes){
        bytesReceived+=tcpClient->bytesAvailable();
        inBlock =tcpClient->readAll();
        localFile->write(inBlock);

        inBlock.resize(0);
    }

    ui->serverProgressBar->setMaximum(int(totalBytes));
    ui->serverProgressBar->setValue(int(bytesReceived));

    if(bytesReceived==totalBytes){
        tcpClient->close();
        localFile->close();
        ui->startButton->setEnabled(true);
        ui->serverStatusLabel->setText(tr("接收文件 %1 成功!").arg(fileName));
    }
}



void Widget::displayError(QAbstractSocket::SocketError error)
{
    qDebug()<<"error:"<< error;
    qDebug()<< "tcpServer->errorString()"<<tcpServer->errorString();

    tcpServer->close();
    tcpClient->close();
    ui->serverProgressBar->reset();
    ui->startButton->setEnabled(true);

}

void Widget::on_startButton_clicked()
{
    start();
}
