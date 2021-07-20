#include "widget.h"
#include "ui_widget.h"

#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    loadSize=4*1024; //4KB
    totalBytes=0;
    bytesWritten=0;
    bytesToWrite=0;
    tcpclient = new QTcpSocket(this);

    //当连接服务器成功时，发出connected()信号，我们开始传送文件
    connect(tcpclient,SIGNAL(connected()),this,SLOT(startTransfer()));


    //当有数据发送成功时，我们更新进度条
    connect(tcpclient,&QTcpSocket::bytesWritten,this,&Widget::updateClientProgress);
    connect(tcpclient,SIGNAL(error(QAbstractSocket::SocketError)),SLOT(displaySocketError));

    ui->sendButton->setEnabled(false);
    ui->clientProgressBar->setValue(0);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::send()
{
    ui->sendButton->setEnabled(false);
    bytesWritten=0;
    ui->clientStatusLabel->setText(tr("链接中"));

    tcpclient->connectToHost(ui->hostLineEdit->text(),
                             quint16(ui->portLineEdit->text().toInt()));
}

void Widget::startTransfer()
{
      localFile = new QFile(fileName);

      if(!localFile->open(QFile::ReadOnly)){
          qDebug()<<"open file error "<<localFile->errorString();
      }


      totalBytes=localFile->size();

      QDataStream sendout(&outBlock,QIODevice::WriteOnly);
//      sendout.setVersion(QDataStream::qt_4_6);

      QString currentFile =fileName.right(
                  fileName.size()-
                  fileName.lastIndexOf('/')-1);

      //依次写入 <<总大小信息空间<<文件名大小信息空间<<文件名
      sendout<<qint64(0)<<qint64(0)<<currentFile;

      totalBytes+=outBlock.size();
      sendout.device()->seek(0);

      //返回outBolock的开始，用实际的大小信息代替两个qint64(0)空间
      sendout<<totalBytes<<qint64(quint64(outBlock.size())-sizeof(qint64)*2);

      bytesToWrite =totalBytes -tcpclient->write(outBlock);
      ui->clientStatusLabel->setText(tr("已链接"));

      outBlock.resize(0);


}

void Widget::updateClientProgress(qint64 numBytes)
{
    //已经发送数据的大小
    bytesWritten+=numBytes;

    if(bytesWritten>0){  //如果已经发送了数据
        outBlock= localFile->read(qMin(bytesToWrite,loadSize));
        bytesToWrite -= tcpclient->write(outBlock);
        outBlock.resize(0);
    }else{
        localFile->close();
    }

    ui->clientProgressBar->setMaximum(int(totalBytes));
    ui->clientProgressBar->setValue(int(bytesWritten));


    // 发送完毕
    if(bytesWritten==totalBytes){
        ui->clientStatusLabel->setText(tr("传送文件 %1 成功").arg(fileName));
        localFile->close();
        tcpclient->close();
    }
}

void Widget::displayError(QAbstractSocket::SocketError error)
{
    qDebug()<<"tcpclient->errorString()"<< tcpclient->errorString();
    qDebug()<<"error"<< error;

    tcpclient->close();
    ui->clientProgressBar->reset();
    ui->clientStatusLabel->setText(tr("客户端就绪"));
    ui->sendButton->setEnabled(true);

}

void Widget::openFile()
{
    fileName = QFileDialog::getOpenFileName(this);
    qDebug()<<"fileName :"<<fileName;
    if(!fileName.isEmpty()){
        ui->sendButton->setEnabled(true);
        ui->clientStatusLabel->setText(tr("打开文件 %1 成功!").arg(fileName));
    }


}


void Widget::on_openButton_clicked()
{
    openFile();
}

void Widget::on_sendButton_clicked()
{
    send();
}
