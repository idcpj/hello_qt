#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    model=new QSqlRelationalTableModel(this);

    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->setTable("student");

    model->setRelation(2,QSqlRelation("course","id","name"));// 2= student 的第二个属性
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NAME"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Course"));

    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));


}

MainWindow::~MainWindow()
{
    delete ui;
}

