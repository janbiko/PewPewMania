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
#include <QDebug>

void Game::updateGame(){
    player->movePlayer();
    player->updatePlayer();
    if (lives->getLives() == 0) {
        timer->stop();
        enemyTimer->stop();
        enemySpawnRateTimer->stop();
        gameOverScreen = new GameOverScreen();
        scene->addItem(gameOverScreen);
        gameOverScreen->setFlag(QGraphicsItem::ItemIsFocusable);
        gameOverScreen->setFocus();
        gameOverTimer->start(200);
    }
}

void Game::spawnEnemy()
{
    enemy = new Enemy(scene->width(), scene->height());
    scene->addItem(enemy);
}

void Game::increaseEnemySpawnRate()
{
    enemyTimer->start(enemySpawnRate);
    if (enemySpawnRate > 100) enemySpawnRate -= 50;
}

void Game::resetGame()
{
    if (gameOverScreen->getGameReset()) {
        score->resetScore();
        lives->resetLives();
        enemySpawnRate = 500;
        timer->start(1000/60);
        enemyTimer->start(enemySpawnRate);
        enemySpawnRateTimer->start(60000);
        ammo->reloadAmmo();
        player->resetPlayer();
        player->setFocus();
        scene->removeItem(gameOverScreen);
        gameOverTimer->stop();
    }
}

Game::Game(QWidget *parent): QWidget(parent)
{
    srand(time(NULL));
    QPixmap background("../assets/img/background.png");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);

    mediaplayer = new MediaPlayer();
    mediaplayer->playBackgroundMusic();



    scene = new QGraphicsScene();

    score = new Score();
    scene->addItem(score);

    lives = new Lives();
    scene->addItem(lives);

    ammo = new Ammo(scene->width());
    scene->addItem(ammo);

    scene->setSceneRect(0, 0, 600, 600);
    scene->setBackgroundBrush(background);
    setMinimumSize(600, 600);
    player = new Player(scene->width(), scene->height());
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);


    gameOverTimer = new QTimer(this);
    connect(gameOverTimer, SIGNAL(timeout()), this, SLOT(resetGame()));



    enemySpawnRateTimer = new QTimer(this);
    connect(enemySpawnRateTimer, SIGNAL(timeout()), this, SLOT(increaseEnemySpawnRate()));
    enemySpawnRateTimer->start(60000);

    enemyTimer = new QTimer(this);
    connect(enemyTimer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
    enemyTimer->start(enemySpawnRate);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGame()));
    timer->start(1000/60);

    QGraphicsView *view = new QGraphicsView(scene, this);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    qDebug() << scene->height();
}


