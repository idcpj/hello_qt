#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QThreadPool>
#include <QDebug>
#include <QString>

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
    void stringChanged(const QString &);

;
};

#endif // MYTHREAD_H
