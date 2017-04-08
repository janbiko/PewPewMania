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

void Game::createUI()
{
    rectUI = new QGraphicsRectItem(0, 0, 600, 50);
    rectUI->setBrush(QBrush(QColor(80, 80, 80, 255)));
    scene->addItem(rectUI);

    score = 55550;
    scoreString = std::to_string(score);
    scoreBoard = new QGraphicsTextItem(QString::fromStdString(scoreString));
    //scoreBoard->setPlainText(QString::fromStdString(score));
    scoreBoard->setDefaultTextColor(Qt::white);
    scoreBoard->setPos(20, 13);
    scoreBoard->setFont(QFont("monospace", 20));
    scene->addItem(scoreBoard);
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

    createUI();

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


