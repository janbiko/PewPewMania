#include "Bullet.h"
#include <QGraphicsScene>

Bullet::Bullet(int x, int y, char c) : QObject(), QGraphicsRectItem()
{
    direction = c;
    bX = x;
    bY = y;
    if(c == 'r'){
        setRect(bX, bY, bWidth, bHeight);
    }
    else if(c == 'l'){
        setRect(bX-, bY, bWidth, bHeight);
    }
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


