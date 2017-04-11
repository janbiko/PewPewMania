#include "Enemy.h"
#include "Player.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <stdlib.h>
#include <QList>
#include <iostream>

Enemy::Enemy(): QObject(), QGraphicsPixmapItem()
{
    // random Position
    int randomY = rand() % 600;
    setPos(randomSpawnSide(), randomY);

    eMovementTimer = new QTimer(this);
    connect(eMovementTimer, SIGNAL(timeout()), this, SLOT(move()));
    eMovementTimer->start(1000/144);

    eAnimationTimer = new QTimer(this);
    if(eSpawnSide == 'l') {
        connect(eAnimationTimer, SIGNAL(timeout()), this, SLOT(animateRightWalkingEnemy()));
        eAnimationTimer->start(120);
    } else {
        connect(eAnimationTimer, SIGNAL(timeout()), this, SLOT(animateLeftWalkingEnemy()));
        eAnimationTimer->start(120);
    }
}

void Enemy::move()
{
    if(!checkForPlayerCollision()) {
        if(eSpawnSide == 'l') {
            moveBy(0.75, 0);
        }
        else if(eSpawnSide == 'r'){
            moveBy(-0.75, 0);
        }
        if(x()> 660){
            scene()->removeItem(this);
            delete this;
        }
        else if(x()<-60){
            scene()->removeItem(this);
            delete this;
        }
    }
}

void Enemy::animateLeftWalkingEnemy()
{
    if(eCurrentFrame == 4) eCurrentFrame = 0;
    if(eCurrentFrame == 0) {
        setPixmap(QPixmap("../assets/img/enemy/EnemyWalkLeft0.png"));
        ++eCurrentFrame;
    } else if(eCurrentFrame == 1) {
        setPixmap(QPixmap("../assets/img/enemy/EnemyWalkLeft1.png"));
        ++eCurrentFrame;
    } else if(eCurrentFrame == 2) {
        setPixmap(QPixmap("../assets/img/enemy/EnemyWalkLeft2.png"));
        ++eCurrentFrame;
    } else if(eCurrentFrame == 3) {
        setPixmap(QPixmap("../assets/img/enemy/EnemyWalkLeft3.png"));
        ++eCurrentFrame;
    }
}

void Enemy::animateRightWalkingEnemy()
{
    if(eCurrentFrame == 4) eCurrentFrame = 0;
    if(eCurrentFrame == 0) {
        setPixmap(QPixmap("../assets/img/enemy/EnemyWalkRight0.png"));
        ++eCurrentFrame;
    } else if(eCurrentFrame == 1) {
        setPixmap(QPixmap("../assets/img/enemy/EnemyWalkRight1.png"));
        ++eCurrentFrame;
    } else if(eCurrentFrame == 2) {
        setPixmap(QPixmap("../assets/img/enemy/EnemyWalkRight2.png"));
        ++eCurrentFrame;
    } else if(eCurrentFrame == 3) {
        setPixmap(QPixmap("../assets/img/enemy/EnemyWalkRight3.png"));
        ++eCurrentFrame;
    }
}

int Enemy::randomSpawnSide()
{
    int randomSpawn = rand() % 2;
    if(randomSpawn == 0){
        eSpawnSide = 'l';
        return -50;
    }
    else{
        eSpawnSide = 'r';
        return 650;
    }
}

bool Enemy::checkForPlayerCollision()
{
    colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); ++i) {
        if(typeid(*(colliding_items[i])) == typeid(Player)) {
            lives->decreaseLives();
            scene()->removeItem(this);
            delete this;
            return true;
        }
    }
    return false;
}







