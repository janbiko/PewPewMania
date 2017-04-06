#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsItem>
#include <iostream>
#include <QObject>
#include <QGraphicsScene>

class Bullet : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bullet(int x, int y, char c);
    void moveBullet();
private:
    int bWidth = 5;
    int bHeight = 1;
    int bSpeed = 6;
    int sWidth = 600;
    int bX, bY;
    char direction;
};

#endif // BULLET_H
