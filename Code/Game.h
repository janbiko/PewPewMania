#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Enemy.h"
#include "mediaplayer.h"
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
    void spawnEnemy();
    void increaseEnemySpawnRate();

private:
    QGraphicsScene *scene;
    Player *player;
    Enemy *enemy;
    QTimer *enemyTimer;
    MediaPlayer *mediaplayer;
    int enemySpawnRate = 500;
};

#endif // GAME_H
