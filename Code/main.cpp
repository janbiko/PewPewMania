#include <QApplication>
#include "Game.h"
#include <QGraphicsScene>

#include "Score.h"
#include "Lives.h"
#include "Ammo.h"

Score * score;
Lives * lives;
Ammo * ammo;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game game;
    game.show();

    return a.exec();
}
