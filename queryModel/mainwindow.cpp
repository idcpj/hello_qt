#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlQuery>
#include <mysqlquerymodel.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // 1. 使用原生
//    QSqlQueryModel *model = new QSqlQueryModel;
//    model->setQuery("select * from student");
//    model->setHeaderData(0, Qt::Horizontal, tr("id"));
//    model->setHeaderData(1, Qt::Horizontal, tr("name"));
//    QTableView *view = new QTableView;
//    view->setModel(model);
//    view->show();

    //2. 创建自己模型的对象
    MySqlQueryModel *myModel=new MySqlQueryModel();
    myModel->setQuery("select * from student");
    myModel->setHeaderData(0, Qt::Horizontal, tr("id"));
    myModel->setHeaderData(1, Qt::Horizontal, tr("name"));
    QTableView *view1 = new QTableView;
    view1->setWindowTitle("mySqlQueryModel"); //修改窗口标题
    view1->setModel(myModel);
    view1->show();


}
