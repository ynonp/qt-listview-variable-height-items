#ifndef MYMODEL_H
#define MYMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "listitem.h"

class MyModel : public QAbstractListModel
{
public:
    MyModel();
    ~MyModel();
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

public:
    void setItems(QList<ListItem> items);

private:
    QList<ListItem> _items;

};

#endif // MYMODEL_H
