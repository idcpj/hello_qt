#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::newFile()
{

}

bool MainWindow::maybeSave()
{

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
