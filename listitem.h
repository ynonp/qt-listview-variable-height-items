#ifndef LISTITEM_H
#define LISTITEM_H
#include <QString>
#include <QMetaType>

class ListItem
{
public:
    ListItem(QString name, int price, QString comments);
    ListItem(const ListItem &other);
    ListItem();

public:
    const ListItem &operator=(const ListItem &other);

public:
    const QString &getName() const;
    int getPrice() const;
    const QString &getComments() const;

private:
    QString _name;
    int _price;
    QString _comments;
};

Q_DECLARE_METATYPE(ListItem);

#endif // LISTITEM_H
