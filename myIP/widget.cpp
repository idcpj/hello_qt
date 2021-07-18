#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QString localhostName = QHostInfo::localHostName();
//    qDebug()<<localhostName;

//    QHostInfo info =  QHostInfo::fromName(localhostName);

//    foreach(QHostAddress address,info.addresses()){
//        if(address.protocol() ==QAbstractSocket::IPv4Protocol){
//            qDebug()<<"add"<<address.toString();
//        }
//    }

    QHostInfo::lookupHost("www.qter.org",this,SLOT(lookedUp(QHostInfo)));


    QList<QNetworkInterface> list =  QNetworkInterface::allInterfaces();

    foreach(QNetworkInterface interface,list){
        qDebug()<<"name"<<interface.name();
        qDebug()<<"hardwareAddress"<<interface.hardwareAddress();
        qDebug()<<"========";


        QList<QNetworkAddressEntry>  entryList =  interface.addressEntries();
        foreach(QNetworkAddressEntry en,entryList ){
            qDebug()<<"ip"<<  en.ip().toString();
            qDebug()<<"netmark"<<  en.netmask().toString();
            qDebug()<<"broadcast"<<en.broadcast().toString();
            qDebug()<<"----------";

        }


    }

}

Widget::~Widget()
{
    delete ui;
}

void Widget::lookedUp(const QHostInfo &host)
{
    qDebug()<<"host.addresses()"<<host.addresses().first();
}

