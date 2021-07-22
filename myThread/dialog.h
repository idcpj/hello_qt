#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMutex>

#include "mythread.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_startButton_clicked();

    void on_stopButton_clicked();

private:
    Ui::Dialog *ui;

    MyThread thread;

public slots:
    void changeString(const QString &);
};
#endif // DIALOG_H
