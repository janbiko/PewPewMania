#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include <QDebug>
#include <QGraphicsScene>

Bullet::Bullet(int x, int y): QObject(), QGraphicsRectItem()
{
    setRect(x, y, 5, 1);
    qDebug() << "Bullet created.";
}

void Bullet::moveBulletR()
{
    checkForEnemyCollision();
    moveBy(5, 0);
    if(this->x() > 600) {
        scene()->removeItem(this);
        delete this;
    }
}

void Bullet::moveBulletL()
{
    checkForEnemyCollision();
    moveBy(-5, 0);
    if(this->x() < -600) {
        scene()->removeItem(this);
        delete this;
    }
}

void Bullet::checkForEnemyCollision()
{
    colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); ++i) {
        if(typeid(*(colliding_items[i])) == typeid(Enemy)) {
            // increase score
            score->increaseScore();


            scene()->removeItem(colliding_items.at(i));
            delete colliding_items.at(i);

            //scene()->removeItem(this);
            //delete this;

            return;
        }
    }
}
