#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    dia=new MyDialog(this);
    connect(dia,&MyDialog::dlgReturn,this,&Widget::receiveInt);
    dia->show();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::receiveInt(int num)
{

    ui->lineEdit->setText(QString::number(num));
}

