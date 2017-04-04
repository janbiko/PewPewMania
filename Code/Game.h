#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <QWidget>
#include <QAbstractAnimation>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>

class Game : public QWidget
{
    Q_OBJECT
public:
    Game(QWidget *parent = 0);

private:
    QGraphicsScene *scene;
    Player *player;
};

#endif // GAME_H
