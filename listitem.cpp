#include "listitem.h"

ListItem::ListItem(QString name, int price, QString comments):
    _name(name),
    _price(price),
    _comments(comments)
{
}

ListItem::ListItem(const ListItem &other):
    _name(other.getName()),
    _price(other.getPrice()),
    _comments(other.getComments())
{
}

ListItem::ListItem()
{
}


const ListItem &ListItem::operator=(const ListItem &other)
{
    _comments = other.getComments();
    _name = other.getName();
    _price = other.getPrice();
    return *this;
}

const QString &ListItem::getName() const
{
    return _name;
}

int ListItem::getPrice() const
{
    return _price;
}

const QString &ListItem::getComments() const
{
    return _comments;
}
