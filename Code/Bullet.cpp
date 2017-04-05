#include "Bullet.h"

Bullet::Bullet(int x, int y) : QObject(), QGraphicsRectItem()
{
    setRect(x, y, 5, 1);
}

