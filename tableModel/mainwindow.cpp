#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QSqlTableModel>
#include <QStyleFactory>
#include <QSqlError>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    model = new QSqlTableModel(this);
    model->setTable("student");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setStyle(QStyleFactory::create("Fusion"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    model->database().transaction();

    if(model->submitAll()){
        model->database().commit();
    }else{
        model->database().rollback();
        QMessageBox::warning(this,tr("tableModel"),tr("数据库错误%1").arg(model->lastError().text()));
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    model->revertAll();
}

void MainWindow::on_pushButton_7_clicked()
{
    auto username=ui->lineEdit->text();
    if(!username.isEmpty()){
        model->setFilter(QString("name = '%1'")
                         .arg(ui->lineEdit->text()));
    }else{
        model->setFilter("");
    }
    model->select();

}

void MainWindow::on_pushButton_8_clicked()
{
    model->setFilter("");
    model->select();
}

void MainWindow::on_pushButton_5_clicked()
{
    model->setSort(0,Qt::SortOrder::AscendingOrder);
    model->select();
}

void MainWindow::on_pushButton_6_clicked()
{
    qDebug()<<model->fieldIndex("id");
    model->setSort(0,
                   Qt::SortOrder::DescendingOrder);

    model->select();


}

void MainWindow::on_pushButton_4_clicked()
{


    QModelIndex index=ui->tableView->currentIndex();
    qDebug()<<index.row();
    model->removeRow(index.row());

    int res = QMessageBox::warning(this,tr("delete row"),
                         tr("do you delete the row"),
                                   QMessageBox::Yes|
                                   QMessageBox::Cancel);

    if(res ==QMessageBox::Yes){
        model->submitAll();
    }else{
        model->revertAll();
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    int row = model->rowCount();
    model->insertRow(row);
    model->setData(model->index(row,0),10);
    // model->submitAll(); //可直接提交
}
