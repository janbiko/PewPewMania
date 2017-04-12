#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>
#include <typeinfo>
#include "Lives.h"

extern Lives * lives;

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy();

public slots:
    void move();
    void animateLeftWalkingEnemy();
    void animateRightWalkingEnemy();

private:
    int randomSpawnSide();
    bool checkForPlayerCollision();
    QList<QGraphicsItem *> colliding_items;
    QTimer * eMovementTimer;
    QTimer * eAnimationTimer;
    int eCurrentFrame = 0;
    char eSpawnSide;
    int eHeight = 34;
    int eWidth = 29;
    bool gameOver();

};

#endif // ENEMY_H
