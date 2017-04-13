#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <QGraphicsTextItem>
#include "Score.h"
#include <QKeyEvent>

extern Score * score;

class GameOverScreen: public QGraphicsTextItem
{
public:
    GameOverScreen(QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent *event);
    bool getGameReset();

private:
    bool gameReset = false;
};

#endif // GAMEOVERSCREEN_H
