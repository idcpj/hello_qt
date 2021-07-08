#include "logindlg.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}


QDialog::DialogCode MainWindow::run(){
    LoginDlg *login = new LoginDlg(this);
    return QDialog::DialogCode(login->exec());

}

MainWindow::~MainWindow()
{
    delete ui;
}

