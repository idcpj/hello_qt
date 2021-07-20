#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QDebug>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
    void stop();


protected:
    void run() override;

private:
    volatile bool stopped=false;

Q_SIGNALS:

public slots:
};

#endif // MYTHREAD_H
