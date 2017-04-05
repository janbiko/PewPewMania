#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include <QWidget>
#include <QAbstractAnimation>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>

class Game : public QWidget
{
    Q_OBJECT
public:
    Game(QWidget *parent = 0);
public slots:
    void updateGame();


private:
    QGraphicsScene *scene;
    Player *player;
    Bullet *bullet;
};

#endif // GAME_H
