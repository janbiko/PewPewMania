#include "Game.h"
#include <QGraphicsScene>

Game::Game()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 600, 600);
    player = new Player();
    player->setPos(300, 300);
    scene->addItem(player);
    scene->update();
}

