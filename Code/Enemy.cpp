#include "Enemy.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>

Enemy::Enemy(): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap("../assets/img/EnemyModel.png"));
    mWidth = 29;
    mHeight = 34;
    mY = y();
    mX = x();
}

void Enemy::move()
{
    moveBy(100, 0);
}







