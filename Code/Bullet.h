#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include "Score.h"

extern Score * score;

class Bullet: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bullet(int x, int y);

private:
    QList<QGraphicsItem *> colliding_items;
    bool checkForEnemyCollision();
    int pBulletWidth = 5;
    int pBulletHeight = 1;
    int pBulletSpeed = 5;

public slots:
    void moveBulletR();
    void moveBulletL();
};

#endif // BULLET_H
