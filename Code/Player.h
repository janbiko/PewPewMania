#ifndef PLAYER_H
#define PLAYER_H

#include "Bullet.h"
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
    Bullet *bullet;
    void initValues();
    void shoot();
    bool facingRight;
    int pHeight, pWidth;
    int pX, pY, pSpeed;
    int sWidth, sHeight;
    bool keyLeftPressed, keyRightPressed, keyUpPressed, keyDownPressed;

};

#endif // PLAYER_H
