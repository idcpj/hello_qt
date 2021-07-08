#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void newFile();
    bool maybeSave(); //判断是否需要保存
    bool save();
    bool saveAs();
    bool saveFile(const QString &fileName);


private:
    Ui::MainWindow *ui;

    bool isUntitled;// 文件是否被保存过
    QString curFile;// 保存当前文件的路径


};
#endif // MAINWINDOW_H
