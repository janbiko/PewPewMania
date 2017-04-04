#include "Game.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBrush>
#include <QImage>
#include "Player.h"
#include <QGraphicsItem>

Game::Game(QWidget *parent): QWidget(parent)
{



    QPixmap background("../assets/img/background.png");
     background = background.scaled(this->size(), Qt::IgnoreAspectRatio);



    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 600, 600);
    scene->setBackgroundBrush(background);


    Player *player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    QGraphicsView *view = new QGraphicsView(scene, this);
}

