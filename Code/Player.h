#ifndef PLAYER_H
#define PLAYER_H

#include "Game.h"
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();

private:
    int mHeight, mWidth;
    int pX, pY;
    void keyPressEvent(QKeyEvent*);
};

#endif // PLAYER_H
