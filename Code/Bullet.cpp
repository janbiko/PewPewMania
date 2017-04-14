#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include <QDebug>
#include <QGraphicsScene>

Bullet::Bullet(int x, int y): QObject(), QGraphicsRectItem()
{
    setRect(x, y, pBulletWidth, pBulletHeight);
}

void Bullet::moveBulletR()
{
    if (!checkForEnemyCollision()) {
        moveBy(pBulletSpeed, 0);
        if(this->x() > 600) {
            scene()->removeItem(this);
            delete this;
        }
    }
}

void Bullet::moveBulletL()
{
    if (!checkForEnemyCollision()) {
        moveBy(-pBulletSpeed, 0);
        if(this->x() < -600) {
            scene()->removeItem(this);
            delete this;
        }
    }
}

bool Bullet::checkForEnemyCollision()
{
    colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); ++i) {
        if(typeid(*(colliding_items[i])) == typeid(Enemy)) {
            // increase score
            score->increaseScore();

            scene()->removeItem(colliding_items.at(i));
            delete colliding_items.at(i);

            scene()->removeItem(this);
            delete this;

            return true;
        }
    }
    return false;
}
