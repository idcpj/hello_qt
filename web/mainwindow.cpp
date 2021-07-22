#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHBoxLayout>
#include <QMetaObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    lineEdit=new QLineEdit(this);

    view= new QWebEngineView(this);

    setCentralWidget(view);
    resize(800,600);


    connect(view,&QWebEngineView::loadProgress,this,&MainWindow::setProgress);
    connect(view,&QWebEngineView::titleChanged,this,&MainWindow::adjustTitle);
    connect(view,&QWebEngineView::loadFinished,this,&MainWindow::finishLoading);
    connect(view,&QWebEngineView::loadFinished,this,&MainWindow::loadFinished);

    connect(lineEdit,&QLineEdit::returnPressed,this,&MainWindow::changeLocation);

    ui->toolBar->addAction(view->pageAction(QWebEnginePage::Back));
    ui->toolBar->addAction(view->pageAction(QWebEnginePage::Forward));
    ui->toolBar->addAction(view->pageAction(QWebEnginePage::Reload));
    ui->toolBar->addAction(view->pageAction(QWebEnginePage::Stop));
    ui->toolBar->addWidget(lineEdit);


    view->load(QUrl("http://www.baidu.com"));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadFinished(bool)
{
    qDebug()<<"load finish";
}

void MainWindow::changeLocation()
{

     view->load(QUrl(lineEdit->text()));
     view->setFocus();
}

void MainWindow::setProgress(int p)
{
    progress=p;
    adjustTitle();
}

void MainWindow::adjustTitle()
{
    if(progress<=0 || progress>=100){
        setWindowTitle(view->title());
    }else{
        setWindowTitle(QString("%1 (%2%)")
                       .arg((view->title()))
                       .arg(progress));
    }

}

void MainWindow::finishLoading(bool finished)
{
    if(finished){
        progress=100;
        setWindowTitle(view->title());
    }else{
        setWindowTitle("web page loading error!");
    }

}

