#include "mysqlquerymodel.h"

#include <QColor>
#include <QSqlQuery>
#include <QDebug>

MySqlQueryModel::MySqlQueryModel(QObject *parent):QSqlQueryModel(parent)
{

}

//返回表格是否可更改的标志
Qt::ItemFlags MySqlQueryModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags =  QSqlQueryModel::flags(index);
    if(index.column()==0){
        flags |= Qt::ItemIsEditable;
    }
    return flags;
}

//添加数据
bool MySqlQueryModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.column() <1 ||
            index.column()>2){
        return false;
    }

    QModelIndex primaryKeyIndex =  QSqlQueryModel::index(index.row(),0);
    int id = data(primaryKeyIndex).toInt(); //获取id号
    clear();


    bool ok=false;
    if(index.column()==1){  //第二个属性可更改
        ok=setName(id,value.toString());
    }

    refresh();
    return ok;

}

QVariant MySqlQueryModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlQueryModel::data(index, role);

    qDebug()<<"role"<<role;

    //第一个属性的字体颜色为红色
    if (role == Qt::TextColorRole && index.column() == 0){
        return qVariantFromValue(QColor(Qt::red));
    }

    return value;
}

bool MySqlQueryModel::setName(int studentId, const QString &name)
{
    QSqlQuery query;
    query.prepare("update student set name = ? where id = ?");
    query.addBindValue(name);
    query.addBindValue(studentId);
    return query.exec();
}

void MySqlQueryModel::refresh()
{
   setQuery("select * from student");
   setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
   setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
}
