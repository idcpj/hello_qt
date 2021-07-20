#include "mythread.h"

MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::stop()
{
    stopped=true;
}

void MyThread::run()
{
    qreal i=0;
    while (!stopped) {
        qDebug()<<tr("in MyThread:%1").arg(i++);
    }

    stopped=false;
}
