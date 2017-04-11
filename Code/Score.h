#ifndef SCORE_H
#define SCORE_H

#include <QObject>
#include <QWidget>

#include <QGraphicsTextItem>
#include <QString>
#include <string.h>




class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem * parent = 0);
    void increaseScore();
    int getScore();


private:
    int score;

};

#endif // SCORE_H
