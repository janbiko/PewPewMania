#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Enemy.h"
#include "Score.h"
#include "Lives.h"
#include "mediaplayer.h"
#include <QWidget>
#include <QAbstractAnimation>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QColor>
#include <string.h>
#include <QString>
#include <QGraphicsTextItem>
#include <GameOverScreen.h>

extern Score * score;
extern Lives * lives;
extern Ammo * ammo;

class Game : public QWidget
{
    Q_OBJECT
public:
    Game(QWidget *parent = 0);
    QGraphicsScene *scene;

public slots:
    void updateGame();
    void spawnEnemy();
    void increaseEnemySpawnRate();
    void resetGame();

private:
    Player *player;
    Enemy *enemy;
    GameOverScreen * gameOverScreen;

    QTimer *enemyTimer;
    QTimer * enemySpawnRateTimer;
    QTimer * timer;
    QTimer * gameOverTimer;

    MediaPlayer *mediaplayer;
    int enemySpawnRate = 500;
    //Score * score;
};

#endif // GAME_H
