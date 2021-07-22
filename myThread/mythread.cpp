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
    long i=0;
    while (!stopped) {
        stringChanged(tr("in MyThread: %1").arg(i));
        msleep(1);
        i++;
    }

    stopped=false;
}
