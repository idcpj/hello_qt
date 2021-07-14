#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QMessageBox>
#include <QObject>
#include <QSqlQuery>


static bool createConntion(){


    QSqlDatabase db =QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if(!db.open()){
        QMessageBox::critical(nullptr,QObject::tr("213"),QObject::tr("Unalbe to establisha databse connection"));
    }

    QSqlQuery query;

    query.exec("create table student (id int primart key, name varchar(20))");
    query.exec("insert into student values(0,'first')");
    query.exec("insert into student values(1,'second')");
    query.exec("insert into student values(2,'thrid')");
    query.exec("insert into student values(3,'fifth')");
    return true;

}

#endif // CONNECTION_H
