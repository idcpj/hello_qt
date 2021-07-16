#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtSql/QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <qsqlquery.h>

static bool createConntion(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");

    if(!db.open()){
        qDebug()<<"open db error"<<db.lastError();
        return false;
    }

    QSqlQuery query(db);
    query.exec("create table student(id int primary key,name vchar)");
    query.exec("insert into student values(0,'刘明')");
    query.exec("insert into student values(1,'陈刚')");
    query.exec("insert into student values(2,'王红')");


    return true;



}

#endif // CONNECTION_H
