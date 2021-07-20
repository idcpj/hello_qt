#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QTcpSocket *tcpclient;
    QFile *localFile; //要发送的文件

    qint64 totalBytes; //数据总大小
    qint64 bytesWritten; // 已发送的数据
    qint64 bytesToWrite;   //剩余数据大小
    qint64 loadSize; //每次发送数据的大小, 4KB

    QString fileName;  //保存文件路径

    QByteArray outBlock;  //数据缓冲区，即存放每次要发送的数据

private slots:
    void send(); //连接服务器
    void startTransfer();  //发送文件大小等信息
    void updateClientProgress(qint64);
    void displayError(QAbstractSocket::SocketError);
    void openFile();

    void on_openButton_clicked();
    void on_sendButton_clicked();
};


#endif // WIDGET_H
