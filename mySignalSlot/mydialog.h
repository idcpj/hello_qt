#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = nullptr);
    ~MyDialog();

private:
    Ui::MyDialog *ui;

Q_SIGNALS:
    void  dlgReturn(int);  // 自定义的信号


private slots:
    void on_myButton_clicked();
};

#endif // MYDIALOG_H
