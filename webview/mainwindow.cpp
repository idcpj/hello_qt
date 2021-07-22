#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    view->load(QUrl("http://www.baidu.com"));
    connect(view,&QWebEngineView::urlChanged,this,&MainWindow::urlChanged);
    view->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::urlChanged(const QUrl &url)
{
    qDebug()<<url;
}

