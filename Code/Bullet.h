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
    Bullet(int x, int y, int gameWidth);

private:
    QList<QGraphicsItem *> colliding_items;
    bool checkForEnemyCollision();
    int bBulletWidth = 5;
    int bBulletHeight = 1;
    int bBulletSpeed = 7;
    int bGameWidth;

public slots:
    void moveBulletR();
    void moveBulletL();
};

#endif // BULLET_H
