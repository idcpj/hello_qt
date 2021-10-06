#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QThread>
#include <QImage>
#include <QTimer>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainwindow;
    mainwindow.show();

    return app.exec();
}
