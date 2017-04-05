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

public slots:
    void move();

private:
    int randomSpawnSide();
    char eSpawnSide;
    int eHeight = 34;
    int eWidth = 29;
};

#endif // ENEMY_H
