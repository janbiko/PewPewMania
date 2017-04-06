#include "Bullet.h"
#include <QGraphicsScene>

Bullet::Bullet(int x, int y, char c) : QObject(), QGraphicsRectItem()
{
    direction = c;
    bX = x;
    bY = y;
    setRect(x, y, bWidth, bHeight);

}

void Bullet::moveBullet()
{
    if(bX-bWidth<0 || bX > sWidth){
        scene()->removeItem(this);
        delete this;
    }
    if(direction == 'l'){
        setPos(bX-bSpeed, bY);
    }
    if(direction == 'r'){
        setPos(bX+bSpeed, bY);
    }
}


