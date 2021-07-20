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
    QFile *file;

    qint64 totalBytes;
    qint64 bytesWritten;
    qint64 bytesToWrite;
    qint64 loadSize;

    QString fileName;

    QByteArray outBlock;

private slots:
    void send(); //连接服务器
    void startTransfer();  //发送文件大小等信息
    void updateClientProgress(qint64);
    void displayError(QAbstractSocket::SocketError);
    void openFile();

};


#endif // WIDGET_H
