#include "Score.h"

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    sScore = 0;
    setPlainText(QString("Score: ") + QString::number(sScore));
    setDefaultTextColor(Qt::white);
    setFont(QFont("power green small", sFontSize));
}

void Score::increaseScore()
{
    ++sScore;
    setPlainText(QString("Score: ") + QString::number(sScore));
}

int Score::getScore()
{
    return sScore;
}

void Score::resetScore()
{
    sScore = 0;
    setPlainText(QString("Score: ") + QString::number(sScore));
}
