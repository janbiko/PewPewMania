#ifndef ENEMY_H
#define ENEMY_H

#include <Game.h>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy();


signals:

public slots:
    void move();
private:
    int mHeight, mWidth;
    int mX, mY;
};

#endif // ENEMY_H
