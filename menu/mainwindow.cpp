#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 第二种方式添加aAction
    QAction *openAction = new QAction(tr("&Open"),this);

    QIcon icon(":/icons/images/1.png");
    openAction->setIcon(icon);
    openAction->setShortcut(QKeySequence(tr("Ctrl+O")));
    ui->menu_F->addAction(openAction);



    isUntitled=true; // 初始化为未保存状态
    curFile =tr("未命名,txt");
    setWindowTitle(curFile);

}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::newFile
 */
void MainWindow::newFile()
{

    // 新建文件前判断当前文件是否保存
    // 若保存,则直接新建文件
    if (maybeSave()){
        isUntitled=true;
        curFile=tr("未命名.txt");
        setWindowTitle(curFile);
        ui->textEdit->clear();
        ui->textEdit->setVisible(true);
    }
}

bool MainWindow::maybeSave()
{
    if (ui->textEdit->document()->isModified()){
        QMessageBox box;
        box.setWindowTitle(tr("警告"));
        box.setIcon(QMessageBox::Warning);
        box.setText(curFile+tr("尚未保存,是否保存?"));
        QPushButton *yesBtn=box.addButton(tr("是(&Y)"),
                                          QMessageBox::YesRole);
       box.addButton(tr("否(&N)"),)


    }
}

bool MainWindow::save()
{

}

bool MainWindow::saveAs()
{

}

bool MainWindow::saveFile(const QString &fileName)
{

}
