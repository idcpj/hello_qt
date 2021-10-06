#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLabel *lab = new QLabel(this);
    lab->setText("hello Qt!");
    lab->move(100,50);


    QLabel *lab2 = new QLabel(this);
    lab2->setText(tr("password","mainwindow"));
    lab2->move(100,80);



    QLabel *label3 = new QLabel(this);
    int id = 123;
    QString name="yafei";
    label3->setText(tr("Id is %1,Name is %2").arg(id).arg(name));
    label3->resize(150,12);
    label3->move(100,120);

}

MainWindow::~MainWindow()
{
    delete ui;
}

