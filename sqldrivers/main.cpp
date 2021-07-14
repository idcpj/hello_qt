#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


     QSqlDatabase db =QSqlDatabase::addDatabase("QMYSQL");
     db.setHostName("127.0.0.1");
     db.setPort(3306);
     db.setUserName("root");
     db.setPassword("12345678");
     db.setDatabaseName("antdbms_wang");

     qDebug()<<"asdads";


     if(!db.open()){
         qDebug()<<"db error"<<db.lastError();
     }
     qDebug()<<"111";

     QSqlQuery query(db);
     query.exec("select * fom hs_user");
     while (query.next()) {
         qDebug()<<"value "<< query.value(2).toString();
     }


    return a.exec();
}
