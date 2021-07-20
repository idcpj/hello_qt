#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork>

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

    QTcpServer *tcpServer;
    QTcpSocket *tcpClient;

    qint64 totalBytes;  //存放总大小信息
    qint64 bytesReceived;  //已收到数据的大小
    qint64 fileNameSize;  //文件名的大小信息
    QString fileName; //存放文件名

    QFile *localFile;
    QByteArray inBlock;

private slots:
    void start();
    void acceptConnetion();
    void updateServrProgress();

    void displayError(QAbstractSocket::SocketError);
    void on_startButton_clicked();
};
#endif // WIDGET_H
