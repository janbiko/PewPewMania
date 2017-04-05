#include "Player.h"
#include <QObject>
#include <QGraphicsScene>
#include <QDebug>

Player::Player() : QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap("../assets/img/PlayerModel.png"));
    pX = 300;
    pY = 300;
    setPos(pX, pY);
}

void Player::keyPressEvent(QKeyEvent *event){
    //move Player
    switch(event->key()){
        case Qt::Key_A:
            keyLeftPressed = true;
            break;
        case Qt::Key_D:
            keyRightPressed = true;
            break;
        case Qt::Key_W:
            keyUpPressed = true;
            break;
        case Qt::Key_S:
            keyDownPressed = true;
            break;
    }
}

void Player::keyReleaseEvent(QKeyEvent *event){
    if(!event->isAutoRepeat()){
        switch(event->key()){
            case Qt::Key_A:
                keyLeftPressed = false;
                break;
            case Qt::Key_D:
                keyRightPressed = false;
                break;
            case Qt::Key_W:
                keyUpPressed = false;
                break;
            case Qt::Key_S:
                keyDownPressed = false;
                break;
        }
    }
}

void Player::movePlayer(){
    if(keyLeftPressed) pX -= 2;
    else if(keyRightPressed) pX += 2;
    if(keyUpPressed) pY -= 2;
    else if(keyDownPressed) pY += 2;
}

void Player::updatePlayer(){
    setPos(pX, pY);
}
