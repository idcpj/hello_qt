#include <QApplication>
#include "connection.h"
#include "mainwindow.h"
#include <QDebug>

#define tr QObject::tr

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    if(!createConntion()){
        return 1;
    }

    qDebug()<<"app is start";

    MainWindow w;
    w.show();


    return a.exec();

}


