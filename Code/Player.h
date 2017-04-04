#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();

private:
};

#endif // PLAYER_H
