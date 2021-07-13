#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);

    QSqlDatabase db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:"); // 内存数据库，掉电会丢失
    if(!db.open()){

    }


    return a.exec();
}
