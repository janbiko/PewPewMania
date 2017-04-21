#include "Player.h"
#include "Game.h"

Player::Player(int gameWidth, int gameHeight) : QObject(), QGraphicsPixmapItem()
{
    pGameWidth = gameWidth;
    pGameHeight = gameHeight;
    setPixmap(QPixmap("../assets/img/player/PlayerWalkRight0.png"));
    pX = pGameWidth / 2;
    pY = pGameHeight / 2;
    setPos(pX, pY);
    keyUpPressed = keyDownPressed = keyLeftPressed = keyRightPressed = false;
    pAnimationTimer = new QTimer(this);
    connect(pAnimationTimer, SIGNAL(timeout()), this, SLOT(playerAnimation()));
    mediaplayer = new MediaPlayer();
}

void Player::animatePlayer()
{
    if(keyLeftPressed == true || keyRightPressed == true || keyUpPressed == true || keyDownPressed == true) {
        pAnimationTimer->start(100);
    } else {
        pAnimationTimer->stop();
    }

}

void Player::playerAnimation()
{
    if(pCurrentFrame == 0) {
        if (pFacingSide == 'l') {setPixmap(QPixmap("../assets/img/player/PlayerWalkLeft0.png"));}
        else {setPixmap(QPixmap("../assets/img/player/PlayerWalkRight0.png"));}
        ++pCurrentFrame;
    } else if(pCurrentFrame == 1) {
        if (pFacingSide == 'l') {setPixmap(QPixmap("../assets/img/player/PlayerWalkLeft1.png"));}
        else {setPixmap(QPixmap("../assets/img/player/PlayerWalkRight1.png"));}
        ++pCurrentFrame;
    } else if(pCurrentFrame == 2) {
        if (pFacingSide == 'l') {setPixmap(QPixmap("../assets/img/player/PlayerWalkLeft2.png"));}
        else {setPixmap(QPixmap("../assets/img/player/PlayerWalkRight2.png"));}
        ++pCurrentFrame;
    } else if(pCurrentFrame == 3) {
        if (pFacingSide == 'l') {setPixmap(QPixmap("../assets/img/player/PlayerWalkLeft3.png"));}
        else {setPixmap(QPixmap("../assets/img/player/PlayerWalkRight3.png"));}
        pCurrentFrame = 0;
    }
}

void Player::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Left:
            keyLeftPressed = true;
            animatePlayer();
            break;
        case Qt::Key_Right:
            keyRightPressed = true;
            animatePlayer();
            break;
        case Qt::Key_Up:
            keyUpPressed = true;
            animatePlayer();
            break;
        case Qt::Key_Down:
            keyDownPressed = true;
            animatePlayer();
            break;
        case Qt::Key_Y:     //face left
            pFacingSide = 'l';
            setPixmap(QPixmap("../assets/img/player/PlayerWalkLeft0.png"));
            break;
        case Qt::Key_X:     //face right
            pFacingSide = 'r';
            setPixmap(QPixmap("../assets/img/player/PlayerWalkRight0.png"));
            break;
        case Qt::Key_Space:
            //do the PewPew
            if(pAmmunition > 0) {
                mediaplayer->playShootingSound();
                bulletTimer = new QTimer(this);
                if (pFacingSide == 'r') {
                    bullet = new Bullet(x() + pBulletRXOffset, y() + pBulletYOffset, pGameWidth);
                    scene()->addItem(bullet);
                    connect(bulletTimer, SIGNAL(timeout()), bullet, SLOT(moveBulletR()));
                } else {
                    bullet = new Bullet(x() + pBulletLXOffset, y() + pBulletYOffset, pGameWidth);
                    scene()->addItem(bullet);
                    connect(bulletTimer, SIGNAL(timeout()), bullet, SLOT(moveBulletL()));
                }
                bulletTimer->start(1000 / 60);
                --pAmmunition;
                ammo->decreaseAmmo();
            }
            break;
        case Qt::Key_C:
            // reload ammo
            mediaplayer->playReloadSound();
            pAmmunition = 6;
            ammo->reloadAmmo();
    }
}

void Player::keyReleaseEvent(QKeyEvent *event){
    switch(event->key()){
        case Qt::Key_Left:
            keyLeftPressed = false;
            pAnimationTimer->stop();
            break;
        case Qt::Key_Right:
            keyRightPressed = false;
            pAnimationTimer->stop();
            break;
        case Qt::Key_Up:
            keyUpPressed = false;
            pAnimationTimer->stop();
            break;
        case Qt::Key_Down:
            keyDownPressed = false;
            pAnimationTimer->stop();
            break;
    }
}

void Player::movePlayer(){
    if(keyLeftPressed && pX>=1) pX -= pSpeed;
    else if(keyRightPressed && pX<pGameWidth-pWidth) pX += pSpeed;
    if(keyUpPressed && pY>=15) pY -= pSpeed;
    else if(keyDownPressed && pY<pGameHeight-pHeight-15) pY += pSpeed;
}

void Player::updatePlayer(){
    movePlayer();
    setPos(pX, pY);
}

void Player::resetKeys()
{
    keyUpPressed = keyDownPressed = keyLeftPressed = keyRightPressed = false;
}

void Player::resetAmmo()
{
    pAmmunition = 6;
}

void Player::resetPlayer()
{
    resetKeys();
    resetAmmo();
}

