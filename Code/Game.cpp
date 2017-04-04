#include "Game.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent): QWidget(parent)
{
    QPixmap background("../assets/img/background.png");
     background = background.scaled(this->size(), Qt::IgnoreAspectRatio);



    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 600, 600);
    scene->setBackgroundBrush(background);


    QGraphicsView *view = new QGraphicsView(scene, this);
}

