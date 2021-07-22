#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->ui->axWidget->setControl(QString::fromUtf8("{8856F961-340A-11D0-A96B-00C04FD705A2}"));//注册组件ID
    this->ui->axWidget->setProperty("DisplayAlerts",true);//不显示警告信息
    this->ui->axWidget->setProperty("DisplayScrollBars",true);//不显示滚动条
    QString webstr=QString("www.baidu.com");//设置要打开的网页
    this->ui->axWidget->dynamicCall("Navigate(const QString&)",webstr);//显示网页
}

MainWindow::~MainWindow()
{
    delete ui;
}

