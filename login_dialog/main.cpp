#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    if(w.run()==QDialog::Accepted){

        w.show();

        return a.exec();
    }else{
        return 0;
    }

}
