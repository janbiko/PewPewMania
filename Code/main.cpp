#include "Game.h"
#include "Player.h"
#include <QApplication>
#include <QGraphicsScene>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game game;
    game.show();

    return a.exec();
}
