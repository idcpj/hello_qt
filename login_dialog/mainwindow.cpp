#include "logindlg.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    LoginDlg *login = new LoginDlg(this);
    if(QDialog::DialogCode(login->exec())==QDialog::Accepted){
        show();
        qApp->exec();
    }

}


MainWindow::~MainWindow()
{
    delete ui;
}

