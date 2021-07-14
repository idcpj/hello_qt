#include "mainwindow.h"

#include <QApplication>
#include <QTextCodec>
#include <connection.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(!createConntion()){
        return 1;
    }




    MainWindow w;
    w.show();
    return a.exec();
}
