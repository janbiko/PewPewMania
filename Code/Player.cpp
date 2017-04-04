#include "Player.h"
#include <QObject>
#include <QGraphicsScene>

Player::Player() : QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/assets/img/PlayerModel.png"));
}

