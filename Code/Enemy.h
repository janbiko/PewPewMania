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
    Enemy(int gameWidth, int gameHeigth);

public slots:
    void move();
    void animateLeftWalkingEnemy();
    void animateRightWalkingEnemy();

private:
    int randomSpawnSide();
    bool checkForPlayerCollision();
    double randomSpeed();
    QList<QGraphicsItem *> colliding_items;
    QTimer * eMovementTimer;
    QTimer * eAnimationTimer;
    int eCurrentFrame = 0;
    char eSpawnSide;
    int eHeight = 34;
    int eWidth = 29;
    float eMovementSpeed;
    float eMaxSpeed = 1.0;
    float eMinSpeed = 0.5;
    int eGameWidth;
    int eGameHeight;
    int eWorldBoundOffset = 50;
    bool gameOver();

};

#endif // ENEMY_H
