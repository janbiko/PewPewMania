#include "Player.h"
#include "Game.h"
#include "Bullet.h"
#include <QObject>
#include <QGraphicsScene>
#include <QDebug>

Player::Player() : QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap("../assets/img/PlayerFacingRight.png"));
    pX=pY = 300;
    pSpeed = 4;
    setPos(pX, pY);
    facingSide = 'r';
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
            facingSide = 'l';
            setPixmap(QPixmap("../assets/img/PlayerFacingLeft.png"));
            break;
        case Qt::Key_X:     //face right
            facingSide = 'r';
            setPixmap(QPixmap("../assets/img/PlayerFacingRight.png"));
            break;
        case Qt::Key_C:
            //do the PewPew
            bulletTimer = new QTimer(this);
            if (facingSide == 'r') {
                bullet = new Bullet(x() + 35, y() + 21);
                scene()->addItem(bullet);
                connect(bulletTimer, SIGNAL(timeout()), bullet, SLOT(moveBulletR()));
            } else {
                bullet = new Bullet(x() - 5, y() + 21);
                scene()->addItem(bullet);
                connect(bulletTimer, SIGNAL(timeout()), bullet, SLOT(moveBulletL()));
            }
            bulletTimer->start(1000 / 60);
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
    if(keyLeftPressed && pX>=1) pX -= pSpeed;
    else if(keyRightPressed && pX<sWidth-pWidth) pX += pSpeed;
    if(keyUpPressed && pY>=15) pY -= pSpeed;
    else if(keyDownPressed && pY<sHeight-pHeight-15) pY += pSpeed;
}

void Player::updatePlayer(){
    setPos(pX, pY);
}
