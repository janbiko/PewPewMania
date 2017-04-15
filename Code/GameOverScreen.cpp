#include "GameOverScreen.h"

GameOverScreen::GameOverScreen(int gameWidth, int gameHeight)
{
    gGameWidth = gameWidth;
    gGameHeight = gameHeight;
    setPlainText(QString("Score: ") + QString::number(score->getScore()));
    setDefaultTextColor(Qt::white);
    setFont(QFont("power green small", fontSize));
    setPos(gameWidth / 2 - scoreTextXOffset, gGameHeight / 2 - scoreTextYOffset);

    goText = new QGraphicsTextItem();
    goText->setPlainText(QString("Press Return to restart."));
    goText->setDefaultTextColor(Qt::white);
    goText->setFont(QFont("power green small", fontSize));
    goText->setPos(this->x() - goTextXOffset, this->y() + goTextYOffset);
}

void GameOverScreen::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
        case Qt::Key_Return:
            gameReset = true;
            break;
    }
}

bool GameOverScreen::getGameReset()
{
    return gameReset;
}


