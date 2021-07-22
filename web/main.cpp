

#include <QApplication>
#include <QWebEngineView >
#include <QSslConfiguration>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    QWebEngineView view;

    view.load(QUrl("http://www.baidu.com"));

    view.show();



    return a.exec();
}
