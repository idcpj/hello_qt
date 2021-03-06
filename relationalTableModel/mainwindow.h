#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSqlRelationalTableModel *model;
};
#endif // MAINWINDOW_H
