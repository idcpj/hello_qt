#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
#include <QDebug>
#include <QDir>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    translator.load("../../../myI18N_zh_CN.qm");
    a.installTranslator(&translator);

    qDebug()<<"current applicationDirPath: "<<QCoreApplication::applicationDirPath(); // 文件所在目录
    qDebug()<<"current currentPath: "<<QDir::currentPath();   // 程序工作目录


    MainWindow w;
    w.show();

    return a.exec();
}
