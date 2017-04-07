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

private:
    QList<QGraphicsItem *> colliding_items;
    void checkForEnemyCollision();

public slots:
    void moveBulletR();
    void moveBulletL();
};

#endif // BULLET_H
