#include "mainwindow.h"
#include "connection.h"

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!conntion()){
        return 1;
    }





    MainWindow w;
    w.show();
    return a.exec();
}
