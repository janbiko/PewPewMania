#include "Game.h"
#include <QGraphicsScene>

Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 600, 600);
    Player player = new Player();
    scene->update();
}

