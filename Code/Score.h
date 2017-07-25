#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>

class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem * parent = 0);
    void increaseScore();
    int getScore();
    void resetScore();

private:
    int sScore;
    int sFontSize = 18;

};

#endif // SCORE_H
