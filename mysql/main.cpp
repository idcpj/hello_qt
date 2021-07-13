
#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);

    qDebug()<<"QSqlDatabase::drivers()"<<QSqlDatabase::drivers();

    QSqlDatabase db  =QSqlDatabase::addDatabase("QMYSQL3");
    db.setHostName("127.0.0.1");
    db.setPort(3306);

    db.setUserName("root");
    db.setPassword("www.upsoft01.com");

    db.setDatabaseName("antdbms_aipu");

    qDebug()<<"isValid "<<db.isValid();
    qDebug()<<"isOpenError "<<db.isOpenError();

    if(!db.open()){
        qDebug()<<"open error "<<db.lastError();
        db.close();
        return 1;
    }

    QSqlQuery query(db);
    query.exec("select * from hs_user");

    while(query.next()){
        qDebug()<<query.value(0).toString();
    }


    return a.exec();
}
