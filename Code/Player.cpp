#include "Player.h"
#include <QObject>
#include <QGraphicsScene>

Player::Player(QObject *parent) : QObject(parent), QGraphicsPixmapItem(parent)
{
    setPixmap(PlayerModel);
}

