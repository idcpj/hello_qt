#include "mydialog.h"
#include "ui_mydialog.h"

#include <QPushButton>

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{

    ui->setupUi(this);

    QPushButton *btn =new QPushButton(this);
    btn->setObjectName("myButton");

}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_myButton_clicked()
{
    emit    dlgReturn(ui->spinBox->value());
    close();
}
