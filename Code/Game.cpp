#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
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
    bullet->moveBullet();
}

void Game::spawn()
{
    Enemy *enemy = new Enemy();
    scene->addItem(enemy);
}

void Game::spawnBullet(char c)
{
    Bullet *bullet = new Bullet(player->x(), player->y(), c);
    scene->addItem(bullet);
    std::cout<<player->x()<<"  "<<player->y()<<c<<std::endl;
}

Game::Game(QWidget *parent): QWidget(parent)
{
    srand(time(NULL));
    QPixmap background("../assets/img/background.png");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);

    scene = new QGraphicsScene();

    scene->setSceneRect(0, 0, 600, 600);
    scene->setBackgroundBrush(background);
    setMinimumSize(600, 600);
    player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    connect(player, SIGNAL(shotsFired(char)),this,SLOT(spawnBullet(char)));

    QTimer *enemyTimer = new QTimer(this);
    connect(enemyTimer, SIGNAL(timeout()), this, SLOT(spawn()));
    enemyTimer->start(200);

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGame()));
    timer->start(1000/60);

    QGraphicsView *view = new QGraphicsView(scene, this);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}


