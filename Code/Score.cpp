#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score = 0;

    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("power green small", 18));
}

void Score::increaseScore()
{
    ++score;
    setPlainText(QString("Score: ") + QString::number(score));
    //setDefaultTextColor(Qt::black);
    //setFont(QFont("times", 16));
}

int Score::getScore()
{
    return score;
}

void Score::resetScore()
{
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
}
