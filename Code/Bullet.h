#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsItem>
#include <iostream>
#include <QObject>

class Bullet : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bullet(int x, int y);
private:
};

#endif // BULLET_H
