#include "mydelegate.h"
#include "listitem.h"
#include <QPainter>
#include <QDebug>

void MyDelegate::paintItemWithComments(QPainter * painter, const QStyleOptionViewItem & option, const ListItem &item) const
{
    // item with comments
    QRect topHalf = option.rect.adjusted(0, 0, 0, -1 * (option.rect.height() / 2));
    QRect bottomHalf = option.rect.adjusted(0, option.rect.height() / 2, 0, 0);

    QRect itemName = topHalf.adjusted(0, 0, -1 * option.rect.width() / 3, 0);
    QRect itemPrice = topHalf.adjusted(itemName.right(), 0, 0, 0);
    QRect itemComments = bottomHalf;

    painter->fillRect(bottomHalf, Qt::lightGray);

    painter->drawText(itemName, Qt::AlignVCenter, item.getName());
    painter->drawText(itemPrice, Qt::AlignVCenter, QString::number(item.getPrice()));
    painter->drawText(itemComments, Qt::AlignVCenter, item.getComments());
}

void MyDelegate::paintItemNoComments(QPainter * painter, const QStyleOptionViewItem & option, const ListItem &item) const
{
    // item with comments
    QRect itemName = option.rect.adjusted(0, 0, -1 * option.rect.width() / 3, 0);
    QRect itemPrice = option.rect.adjusted(itemName.right(), 0, 0, 0);

    painter->drawText(itemName, Qt::AlignVCenter, item.getName());
    painter->drawText(itemPrice, Qt::AlignVCenter, QString::number(item.getPrice()));

}

void MyDelegate::paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
    QVariant itemVar = index.data(Qt::UserRole);
    ListItem item = itemVar.value<ListItem>();

    if ( !item.getComments().isEmpty())
    {
        paintItemWithComments(painter, option, item);
    }
    else
    {
        paintItemNoComments(painter, option, item);
    }
}

QSize	MyDelegate::sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const
{
    QVariant itemVar = index.data(Qt::UserRole);
    ListItem item = itemVar.value<ListItem>();

    if ( item.getComments().isEmpty() )
    {
        return QSize(option.rect.width(), 50);
    }
    else
    {
        return QSize(option.rect.width(), 100);
    }
}

MyDelegate::MyDelegate(QObject *parent):
    QStyledItemDelegate(parent)
{

}

MyDelegate::~MyDelegate()
{

}

