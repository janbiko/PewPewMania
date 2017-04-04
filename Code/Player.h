#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsScene>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QObject *parent = 0);

private:
    QPixmap PlayerModel = ":/assets/img/PlayerModel.png";
};

#endif // PLAYER_H
