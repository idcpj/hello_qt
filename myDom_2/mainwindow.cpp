#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file("/Users/idcpj/code/qt/build-myDom_2-Desktop_Qt_5_9_9_clang_64bit-Debug/my.xml");

    if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate)){
        qDebug()<< "open my.xml is error";
        return ;
    }

    QDomDocument doc;
    QDomProcessingInstruction  instruction;
    instruction = doc.createProcessingInstruction("xml","<?xml version='1.0' encoding='UTF-8'?>");
    doc.appendChild(instruction);

    QDomElement root = doc.createElement(tr("书库"));
    doc.appendChild(root); //添加根元素


    // 添加第一个book元素及其子元素
    QDomElement book = doc.createElement(tr("图书"));
    QDomAttr id=doc.createAttribute(tr("编号"));
    QDomElement title = doc.createElement(tr("书名"));
    QDomElement author = doc.createElement(tr("作者"));

    QDomText text;
    id.setValue(tr("1"));
    book.setAttributeNode(id);

    text = doc.createTextNode(tr("Qt"));

    title.appendChild(text);
    text = doc.createTextNode(tr("shiming"));

    author.appendChild(text);
    book.appendChild(title);
    book.appendChild(author);
    root.appendChild(book);


    // 添加第二个book元素及其子元素
    book = doc.createElement(tr("图书"));
    id = doc.createAttribute(tr("编号"));
    title = doc.createElement(tr("书名"));
    author = doc.createElement(tr("作者"));
    id.setValue(tr("2"));
    book.setAttributeNode(id);
    text = doc.createTextNode(tr("Linux"));
    title.appendChild(text);
    text = doc.createTextNode(tr("yafei"));
    author.appendChild(text);
    book.appendChild(title);
    book.appendChild(author);
    root.appendChild(book);

    QString err;

    if(!doc.setContent(&file,&err)){
        qDebug()<<"doc.setContent(&file,&err) "<<err;
        file.close();
        return;
    }

    QTextStream out(&file);
    doc.save(out,4);
    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

