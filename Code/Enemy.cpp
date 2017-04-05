#include "Enemy.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <stdlib.h>

Enemy::Enemy(): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap("../assets/img/EnemyModel.png"));
    mWidth = 29;
    mHeight = 34;

    // random Position

    //setPos(0, random);


    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    moveBy(10, 0);
    if(x() > 500) {
        scene()->removeItem(this);
        delete this;
    }
}







