#include "Lives.h"
#include <QFont>

Lives::Lives(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    lives = 3;

    setPlainText(QString("Lives: ") + QString::number(lives));
    setDefaultTextColor(Qt::white);
    setFont(QFont("power green small", 18));
    setPos(500, y());
}

void Lives::decreaseLives()
{
    --lives;
    setPlainText(QString("Lives: ") + QString::number(lives));
}

int Lives::getLives()
{
    return lives;
}
