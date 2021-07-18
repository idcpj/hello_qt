#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     manager=new QNetworkAccessManager(this);
     ui->progressBar->hide();
     ui->label_2->hide();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startRequest(QUrl url)
{
    reply = manager->get(QNetworkRequest(url));
    qDebug()<<"reply->error()"<<reply->error();


    connect(reply,SIGNAL(readyRead()),this, SLOT(httpReadyRead()));
    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(updateDataReadProgress(qint64,qint64)));
    connect(reply,SIGNAL(finished()),this,SLOT(httpFinished()));

}

void MainWindow::on_pushButton_clicked()
{
    url = ui->lineEdit->text();
    qDebug()<<"url.path()"<<url.path();
    QFileInfo info(url.path());
    qDebug()<<"info.fileName()"<<info.fileName();
    QString fileName(info.fileName());

    if(fileName.isEmpty()){
        fileName="index.html";
    }

    qDebug()<<"fileName"<<fileName;

    file = new QFile(fileName);


    if(!file->open(QIODevice::WriteOnly)){
        qDebug()<<file->error();
        delete  file;
        return;
    }




    startRequest(QUrl(url));
    ui->progressBar->setValue(0);
    ui->progressBar->show();
    ui->label_2->show();

}

void MainWindow::httpFinished()
{
    ui->progressBar->hide();
    ui->label_2->hide();

    file->flush();
    file->close();
    reply->deleteLater();
    delete file;
}

void MainWindow::httpReadyRead()
{
    if(file){
        file->write(reply->readAll());
    }
}

void MainWindow::updateDataReadProgress(qint64 bytesRead, qint64 totalBytes)
{
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesRead);

    ui->label_2->setText(QString::number((bytesRead*100/totalBytes))+"%");
}

