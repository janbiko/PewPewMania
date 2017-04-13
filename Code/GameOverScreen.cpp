#include "GameOverScreen.h"
#include <QFont>
#include <QDebug>

GameOverScreen::GameOverScreen(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    setPlainText(QString("Score: ") + QString::number(score->getScore()) + QString("\n \n") + QString("Press Return to restart."));
    setDefaultTextColor(Qt::white);
    setFont(QFont("power green small", 24));
    setPos(250, 250);
}

void GameOverScreen::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
        case Qt::Key_Return:
            qDebug() << "Läuft";
            gameReset = true;
            break;
    }
    //return false;
}

bool GameOverScreen::getGameReset()
{
    return gameReset;
}


