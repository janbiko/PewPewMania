#include "Player.h"
#include <QObject>
#include <QGraphicsScene>
#include <QDebug>

Player::Player() : QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap("../assets/img/PlayerModel.png"));

}

void Player::keyPressEvent(QKeyEvent *event){
    qDebug() << "Key pressed.";
    pY = y();
    pX = x();
    mWidth = 36;
    mHeight = 37;
    //move Player
    if(event->key() == Qt::Key_W){
        if(pY > mHeight/2) moveBy(0, -10);
    }
    if(event->key() == Qt::Key_S){
        if(pY < 600-mWidth/2) moveBy(0, 10);
    }
    if(event->key() == Qt::Key_A){
        if(pX > mWidth/2) moveBy(-10, 0);
    }
    if(event->key() == Qt::Key_D){
        if(pX < 600-mWidth/2) moveBy(10, 0);
    }
    //do the PewPew
    if(event->key() == Qt::Key_Shift){
        //TBD
    }
}

