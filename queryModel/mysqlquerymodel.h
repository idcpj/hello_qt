#ifndef MYSQLQUERYMODEL_H
#define MYSQLQUERYMODEL_H

#include <QSqlQueryModel>



class MySqlQueryModel : public QSqlQueryModel
{
public:
    MySqlQueryModel(QObject *parent=nullptr);
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool  setData(const QModelIndex &index,const QVariant &value,int role) override;
    QVariant data(const QModelIndex &item, int role = Qt::DisplayRole) const override;

private:

    bool setName(int studentId, const QString &name);
    void refresh();
};

#endif // MYSQLQUERYMODEL_H
