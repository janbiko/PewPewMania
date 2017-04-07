#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Bullet: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bullet(int x, int y);

public slots:
    void moveBullet();
};

#endif // BULLET_H
