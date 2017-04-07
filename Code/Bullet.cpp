#include "Bullet.h"
#include <QDebug>

Bullet::Bullet(int x, int y): QObject(), QGraphicsRectItem()
{
    setRect(x, y, 5, 1);
    qDebug() << "Bullet created.";
}

void Bullet::moveBullet()
{
    moveBy(5, 0);
}
