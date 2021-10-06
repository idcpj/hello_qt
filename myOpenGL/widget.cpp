#include "widget.h"
#include "ui_widget.h"
#include <QSound>

MyGLWidget::MyGLWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    QSound::play("/Users/idcpj/code/learn/qt/WaterSoundButtonDemo/Resource/sound.wav");


}

MyGLWidget::~MyGLWidget()
{
    delete ui;
}
