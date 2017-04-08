#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBrush>
#include <QImage>
#include <stdlib.h>
#include <QGraphicsItem>
#include <iostream>
#include <time.h>
#include <QTime>

void Game::updateGame(){
    player->movePlayer();
    player->updatePlayer();
}

void Game::spawnEnemy()
{
    enemy = new Enemy();
    scene->addItem(enemy);
}

void Game::increaseEnemySpawnRate()
{
    enemyTimer->start(enemySpawnRate);
    if (enemySpawnRate > 100) enemySpawnRate -= 50;
}



Game::Game(QWidget *parent): QWidget(parent)
{
    srand(time(NULL));
    QPixmap background("../assets/img/background.png");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);

    mediaplayer = new MediaPlayer();
    mediaplayer->playBackgroundMusic();

    scene = new QGraphicsScene();

    scene->setSceneRect(0, 0, 600, 600);
    scene->setBackgroundBrush(background);
    setMinimumSize(600, 600);
    player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);


    QTimer * enemySpawnRateTimer = new QTimer(this);
    connect(enemySpawnRateTimer, SIGNAL(timeout()), this, SLOT(increaseEnemySpawnRate()));
    enemySpawnRateTimer->start(60000);

    enemyTimer = new QTimer(this);
    connect(enemyTimer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
    enemyTimer->start(enemySpawnRate);

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGame()));
    timer->start(1000/60);

    QGraphicsView *view = new QGraphicsView(scene, this);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}


