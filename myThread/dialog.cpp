#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

   connect(&thread,&MyThread::stringChanged,this,&Dialog::changeString);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_startButton_clicked()
{
    thread.start();
    ui->startButton->setEnabled(false);
    ui->stopButton->setEnabled(true);
}

void Dialog::on_stopButton_clicked()
{

    if(thread.isRunning()){
        thread.stop();
        ui->startButton->setEnabled(true);
        ui->stopButton->setEnabled(false);
    }
}

void Dialog::changeString(const QString &str)
{
    ui->label->setText(str);
}
