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
#include <QGraphicsRectItem>
#include <QColor>
#include <string.h>
#include <QString>
#include <QGraphicsTextItem>

class Game : public QWidget
{
    Q_OBJECT
public:
    Game(QWidget *parent = 0);
    void createUI();
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
    QGraphicsRectItem *rectUI;
    QGraphicsTextItem *scoreBoard;
    std::string scoreString;
    int score;
};

#endif // GAME_H
