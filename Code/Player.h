#ifndef PLAYER_H
#define PLAYER_H

#include "Game.h"
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void movePlayer();
    void updatePlayer();
private:
    int mHeight, mWidth;
    int pX, pY;
    int dX, dY;
    bool keyLeftPressed, keyRightPressed, keyUpPressed, keyDownPressed;

};

#endif // PLAYER_H
