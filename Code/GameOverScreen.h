#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <QGraphicsTextItem>
#include "Score.h"
#include <QKeyEvent>
#include <QFont>

extern Score * score;

class GameOverScreen: public QGraphicsTextItem
{
public:
    GameOverScreen(int gameWidth, int gameHeight);
    QGraphicsTextItem * goText;
    void keyPressEvent(QKeyEvent *event);
    bool getGameReset();

private:
    bool gameReset = false;
    int gGameWidth;
    int gGameHeight;
    int fontSize = 24;
    int scoreTextXOffset = 75;
    int scoreTextYOffset = 75;
    int goTextXOffset = 125;
    int goTextYOffset = 75;

};

#endif // GAMEOVERSCREEN_H
