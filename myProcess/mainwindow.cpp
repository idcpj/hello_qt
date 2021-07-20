#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("哈哈哈");

    connect(&myProcess,&QProcess::readyRead,this,&MainWindow::showResult);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    myProcess.start("cmd.exe",QStringList()<<"/c dir&pause");

}

void MainWindow::showResult()
{
    qDebug()<<"myProcess.readAll()\n\\n 哈哈哈"<< myProcess.readAll().replace("\\\\","\\");
}
