#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

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
};
#endif // DIALOG_H
