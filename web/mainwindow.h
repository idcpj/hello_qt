#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QMainWindow>
#include <QWebEngineView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWebEngineView *view;
    QLineEdit *lineEdit;
    int progress=0;


private slots:
    void loadFinished(bool);
    void changeLocation();     // 改变路径
    void setProgress(int);     // 更新进度
    void adjustTitle();        // 更新标题显示
    void finishLoading(bool);  // 加载完成后进行处理

};
#endif // MAINWINDOW_H
