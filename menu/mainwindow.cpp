#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QFileDialog>
#include <QMessageBox>
#include <QPushButton>
#include <QTextStream>
#include <QFileInfo>
#include <QtDebug>
#include <QLineEdit>
#include <QDialog>
#include <QPushButton>
#include <QLabel>


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



    isSave=true; // 初始化为未保存状态
    curFile =tr("未命名.txt");
    setWindowTitle(curFile);

    findDlg = new QDialog(this);
    findDlg->setWindowTitle(tr("查找"));
    findLineEdit=new QLineEdit(findDlg);

    QPushButton *nextBtn = new QPushButton(tr("查找下一个"),findDlg);
    //QPushButton *preBtn = new QPushButton(tr("查找上一个"),findDlg);
    QVBoxLayout *layout = new QVBoxLayout(findDlg);
    layout->setDirection(QVBoxLayout::LeftToRight);

    layout->addWidget(findLineEdit);
    layout->addWidget(nextBtn);

    connect(nextBtn,&QPushButton::clicked,[this]{
        showFindText();
    });


    QLabel *label = new QLabel(this);
    label->setText(tr("hello word"));
    label->setMinimumSize(150,20);
    label->setFrameShape(QFrame::WinPanel);
    label->setFrameShadow(QFrame::Sunken);
    ui->statusBar->addWidget(label);


    //ui->statusBar->showMessage(tr("欢迎访问Qt爱好者社区！"),2000);

    QLabel *permanent = new QLabel();
    permanent->setFrameStyle(QFrame::Box|QFrame::Sunken);
    permanent->setText(
                tr("<a href=\"http://www.yafeilinux.com\">yafeilinux.com</a>"));
    permanent->setTextFormat(Qt::RichText);
    permanent->setOpenExternalLinks(true);
    ui->statusBar->addPermanentWidget(permanent);


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
    if (curFileIsSave()){
        isSave=true;
        curFile=tr("未命名.txt");
        setWindowTitle(curFile);
        ui->textEdit->clear();
        ui->textEdit->setVisible(true);
    }
}

bool MainWindow::curFileIsSave()
{
    if (ui->textEdit->document()->isModified()){
        QMessageBox box(this);

        box.setWindowTitle(tr("警告"));
        box.setIcon(QMessageBox::Warning);
        box.setText(curFile+tr("尚未保存,是否保存?"));
        QPushButton *yesBtn=box.addButton(tr("是(&Y)"),
                                          QMessageBox::YesRole);

        box.addButton(tr("否(&N)"),QMessageBox::RejectRole);

        QPushButton *cancelBut  =box.addButton(tr("取消"),QMessageBox::RejectRole);

        box.exec();


        if(box.clickedButton()==yesBtn){
            return save();
        }else if (box.clickedButton()==cancelBut){
            return false;
        }

    }

    return true;
}

bool MainWindow::save()
{

    // 这里如果文档以前没有保存过，
    // 那么执行另存为操作saveAs()，
    // 如果已经保存过，那么调用saveFile()执行文件保存操作
    if(isSave){
        return saveAs();
    }else{
        return saveFile(curFile);
    }

}

bool MainWindow::saveAs()
{
    QString fileName =  QFileDialog::getSaveFileName(this,tr("另存为"),curFile);

    if (fileName.isEmpty()){
        return false;
    }

    return saveFile(fileName);

}

bool MainWindow::saveFile(const QString &fileName)
{
    QFile file(fileName);

    if(!file.open(QFile::WriteOnly|QFile::Text)){


        QMessageBox::warning(this,
                             tr("多文档编辑器"),
                             tr("无法写入文件 %1:/n %2")
                             .arg(fileName)
                             .arg(file.errorString())
                             );
        return false;
    }

    QTextStream out(&file);

    // 鼠标指针变为等待状态
    QApplication::setOverrideCursor(Qt::WaitCursor);

    out<< ui->textEdit->toPlainText();

    // 鼠标指针恢复原来的状态
    QApplication::restoreOverrideCursor();

    isSave=false;

    curFile = QFileInfo(fileName).canonicalFilePath();

    setWindowTitle(curFile);

    return true;

}

bool MainWindow::loadFile(const QString &fileName)
{

    qDebug()<<"fileName:"<<fileName;
    QFile file(fileName);

    if(!file.open(QFile::ReadWrite|QFile::Text)){
        QMessageBox::warning(this,
                             tr("多文档编辑器"),
                             tr("无法读取文件 %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }



    QApplication::setOverrideCursor(Qt::WaitCursor);

    ui->textEdit->setPlainText(QString(file.readAll()));
    QApplication::restoreOverrideCursor();

    curFile = QFileInfo(fileName).canonicalFilePath();
    isSave = false;


    qDebug() << "curFile:"<<curFile;
    setWindowTitle(curFile);

    return true;
}

void MainWindow::on_action_file_triggered()
{
    newFile();
}


void MainWindow::on_action_save_triggered()
{
    save();
}

void MainWindow::on_action_saveas_triggered()
{
    saveAs();
}

void MainWindow::on_action_open_triggered()
{
    if(curFileIsSave()){
        QString fileName=QFileDialog::getOpenFileName(this);
        if(!fileName.isEmpty()){
            loadFile(fileName);
            ui->textEdit->setVisible(true);
        }

    }
}


void MainWindow::on_action_close_triggered()
{
    if(curFileIsSave()){
        ui->textEdit->setVisible(false);
    }
}

void MainWindow::on_action_quit_triggered()
{
    on_action_close_triggered();

    qApp->quit();
}


void MainWindow::on_action_undo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_action_cut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_action_copy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_action_paste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    if(curFileIsSave()){
        event->accept();
    }else{
        event->ignore();
    }
}

void MainWindow::showFindText()
{
    QString content= findLineEdit->text();
    if(!ui->textEdit->find(content,QTextDocument::FindBackward)){
        QMessageBox::warning(this,
                             tr("查找"),
                             tr("找不到%1").arg(content));
    }
}

void MainWindow::on_action_find_triggered()
{
    findDlg->show();
}
