#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBrush>
#include <QImage>

#include <QGraphicsItem>
#include <iostream>

void Game::updateGame(){
    player->movePlayer();
    player->updatePlayer();
}

Game::Game(QWidget *parent): QWidget(parent)
{
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

    Enemy *enemy = new Enemy();
    enemy->move();
    scene->addItem(enemy);

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGame()));
    timer->start(1000/60);

    QGraphicsView *view = new QGraphicsView(scene, this);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
