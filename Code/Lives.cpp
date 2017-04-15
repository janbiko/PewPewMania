#include "Lives.h"

Lives::Lives(int gameWidth)
{
    lGameWidth = gameWidth;
    lLives = 3;
    setPlainText(QString("Lives: ") + QString::number(lLives));
    setDefaultTextColor(Qt::white);
    setFont(QFont("power green small", lFontSize));
    setPos(lGameWidth - lLivesXOffset, y());
}

void Lives::decreaseLives()
{
    --lLives;
    setPlainText(QString("Lives: ") + QString::number(lLives));
}

int Lives::getLives()
{
    return lLives;
}

void Lives::resetLives()
{
    lLives = 3;
    setPlainText(QString("Lives: ") + QString::number(lLives));
}
