#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQuery>

static bool conntion(){
    QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if(!db.open()){
        QMessageBox::warning(nullptr,
                             QObject::tr("open db error"),
                             QObject::tr("your db open is error")
                             );
    }
    QSqlQuery query;
    query.exec("create table student (id int primary key,name varchar)");
    query.exec("insert into student values(0,'yafe0')");
    query.exec("insert into student values(1,'yafe1')");
    query.exec("insert into student values(2,'yafe2')");

    return true;
}


#endif // CONNECTION_H
