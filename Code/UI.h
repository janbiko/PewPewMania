#ifndef UI_H
#define UI_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QColor>
#include <QGraphicsTextItem>
#include <QString>
#include <string.h>

#include <QGraphicsPixmapItem>


class UI : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    UI();
    QGraphicsRectItem *rectUI;
    QGraphicsTextItem *scoreBoard;

private:
    std::string scoreString;
    int score;

};

#endif // UI_H
