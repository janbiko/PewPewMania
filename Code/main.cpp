#include <QApplication>
#include "Game.h"
#include <QGraphicsScene>

#include "Score.h"

Score * score;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game game;
    game.show();

    return a.exec();
}
