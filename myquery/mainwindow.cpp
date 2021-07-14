#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QSqlQuery query;

    //query.exec(QString("select * from student where id=%1").arg(ui->spinBox->value()));
    query.prepare("select * from student where id=?");
    query.addBindValue(ui->spinBox->value());
    query.exec();

    while (query.next()) {
        qDebug()<<"id,name"<<query.value(0).toString()<<query.value(1).toString();
        ui->label->setText("id,name"+query.value(0).toString()+query.value(1).toString());
    }

    QSqlDatabase::database().transaction();

    QSqlDatabase::database().rollback();



}
