#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QMessageBox>

static bool createConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    if(!db.open()){
        QMessageBox::critical(nullptr,tr("cannot open database"),
                              )
    }
}

#endif // CONNECTION_H
