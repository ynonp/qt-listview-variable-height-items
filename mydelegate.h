#ifndef MYDELEGATE_H
#define MYDELEGATE_H

#include <QStyledItemDelegate>

class ListItem;

class MyDelegate : public QStyledItemDelegate
{
public:
    Q_OBJECT

    virtual void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;
    virtual QSize	sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const;

    void paintItemWithComments(QPainter * painter, const QStyleOptionViewItem & option, const ListItem &item) const;
    void paintItemNoComments(QPainter * painter, const QStyleOptionViewItem & option, const ListItem &item) const;

public:
    MyDelegate(QObject *parent = NULL);
    ~MyDelegate();
};

#endif // MYDELEGATE_H
