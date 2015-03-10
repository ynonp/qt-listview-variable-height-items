#include "mymodel.h"

MyModel::MyModel(QObject *parent):
    QAbstractListModel(parent)
{
    // creating a default list of items
    _items << ListItem("Apples", 10, "");
    _items << ListItem("Bananas", 20, "recommended!");
    _items << ListItem("Carrots", 30, "");

}

int MyModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    return _items.length();
}

QVariant MyModel::data(const QModelIndex & index, int role) const
{
    ListItem item = _items.at(index.row());

    if ( role == Qt::DisplayRole )
    {
        return item.getName();
    }
    else if ( role == Qt::UserRole )
    {
        QVariant res;
        res.setValue(item);
        return res;
    }
    else
    {
        return QVariant::Invalid;
    }
}

void MyModel::setItems(QList<ListItem> items)
{
    _items = items;
    emit dataChanged(index(0, 0), index(items.length(), 0));
}

MyModel::~MyModel()
{

}

