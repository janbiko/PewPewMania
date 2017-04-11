#include "Lives.h"
#include <QFont>

Lives::Lives(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    lives = 3;

    setPlainText(QString("Lives: ") + QString::number(lives));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times", 16));

    setPos(500, y());
}

void Lives::decreaseLives()
{
    lives--;
    setPlainText(QString("Lives: ") + QString::number(lives));
    //setDefaultTextColor(Qt::black);
    //setFont(QFont("times", 16));
}

int Lives::getLives()
{
    return lives;
}
