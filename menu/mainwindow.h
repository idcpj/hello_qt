#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>

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
    bool curFileIsSave(); //判断是否需要保存
    bool save();
    bool saveAs();
    bool saveFile(const QString &fileName);
    bool loadFile(const QString &fileName);


private slots:
    void on_action_file_triggered();

    void on_action_saveas_triggered();

    void on_action_save_triggered();

    void on_action_open_triggered();

    void on_action_close_triggered();

    void on_action_quit_triggered();

    void on_action_undo_triggered();

    void on_action_cut_triggered();

    void on_action_copy_triggered();

    void on_action_paste_triggered();

private:
    Ui::MainWindow *ui;

    bool isSave;// 文件是否被保存过
    QString curFile;// 保存当前文件的路径

protected:
    void closeEvent(QCloseEvent *event);

};
#endif // MAINWINDOW_H
