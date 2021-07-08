#include "logindlg.h"
#include "ui_logindlg.h"

#include <QMessageBox>

LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);

}

LoginDlg::~LoginDlg()
{
    delete ui;
}

void LoginDlg::on_loginBtn_clicked()
{
    if(ui->userlineEdit->text().trimmed()=="root" &&
            ui->pwdlineEdi->text()=="root")
    {

        accept();
    }else{
        QMessageBox::warning(this,tr("警告"),tr("user input user or password is erro!"),QMessageBox::Yes);

        ui->userlineEdit->text().clear();
        ui->pwdlineEdi->text().clear();
        ui->userlineEdit->setFocus();

    }
}
