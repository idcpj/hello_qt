#include <QCoreApplication>
#include <QDomDocument>
#include <QFile>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDomDocument doc;
    QFile file("my.xml");
    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"open error";
        return 0;
    }

    QString  err;
    if(!doc.setContent(&file,&err)){
        qDebug()<<err;
        file.close();
        return 0;
    }

    file.close();
    QDomNode firstNode= doc.firstChild();
    qDebug()<< firstNode.nodeName()<<firstNode.nodeValue();
    // output: "xml" "version='1.0' encoding='UTF-8'"


    QDomElement docElem = doc.documentElement();  //返回根元素
    QDomNode n = docElem.firstChild(); //返回根节点的第一个子节点
    while (!n.isNull()) {
        if(n.isElement()){
            QDomElement e =n.toElement();
            qDebug()<<e.tagName()<<e.attribute("id");

            QDomNodeList list= e.childNodes();

            for(int i=0;i<list.count();i++){
                QDomNode node = list.at(i);
                if(node.isElement()){
                    qDebug()<< "    "+node.toElement().tagName()
                            << node.toElement().text();
                }
            }
        }

        n=n.nextSibling();
    }





    return a.exec();
}
