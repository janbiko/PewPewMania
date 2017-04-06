#include "Player.h"
#include "Game.h"
#include <QObject>
#include <QGraphicsScene>
#include <QDebug>

Player::Player() : QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap("../assets/img/PlayerFacingRight.png"));
    pX=pY = 300;
    pSpeed = 4;
    sWidth=sHeight = 600;
    setPos(pX, pY);
    keyUpPressed = keyDownPressed = keyLeftPressed = keyRightPressed = false;
}

void Player::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Left:
            keyLeftPressed = true;
            break;
        case Qt::Key_Right:
            keyRightPressed = true;
            break;
        case Qt::Key_Up:
            keyUpPressed = true;
            break;
        case Qt::Key_Down:
            keyDownPressed = true;
            break;
        case Qt::Key_Y:     //face left
            facingRight = false;
            setPixmap(QPixmap("../assets/img/PlayerFacingLeft.png"));
            break;
        case Qt::Key_X:     //face right
        facingRight = true;
            setPixmap(QPixmap("../assets/img/PlayerFacingRight.png"));
            break;
        case Qt::Key_C:
            //insert the PewPew
            shoot();
            break;
    }
}

void Player::keyReleaseEvent(QKeyEvent *event){
    if(!event->isAutoRepeat()){
        switch(event->key()){
            case Qt::Key_Left:
                keyLeftPressed = false;
                break;
            case Qt::Key_Right:
                keyRightPressed = false;
                break;
            case Qt::Key_Up:
                keyUpPressed = false;
                break;
            case Qt::Key_Down:
                keyDownPressed = false;
                break;
        }
    }
}

void Player::movePlayer(){
    if(keyLeftPressed) pX -= pSpeed;
    else if(keyRightPressed) pX += pSpeed;
    if(keyUpPressed) pY -= pSpeed;
    else if(keyDownPressed) pY += pSpeed;
}

void Player::updatePlayer(){
    setPos(pX, pY);
}

void Player::shoot()
{
    if(facingRight){
        bullet = new Bullet(pX+pWidth/2, pY, 'r');
    }
    if(!facingRight){
        bullet = new Bullet(pX-pWidth/2, pY, 'l');
    }
}
