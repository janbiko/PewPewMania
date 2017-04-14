#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <Bullet.h>
#include "Score.h"
#include "Ammo.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "mediaplayer.h"

extern Ammo * ammo;

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void movePlayer();
    void updatePlayer();
    void resetKeys();

public slots:
    void animateRightWalkingPlayer();
    void animateLeftWalkingPlayer();

private:
    void initValues();
    void shoot();
    char facingSide;
    int pHeight = 37;
    int pWidth = 36;
    int pX, pY, pSpeed;
    int sWidth = 600;
    int sHeight = 600;
    bool keyLeftPressed, keyRightPressed, keyUpPressed, keyDownPressed;
    Bullet * bullet;
    QTimer * bulletTimer;
    int pCurrentFrame = 0;
    QTimer * pAnimationTimer;
    void animatePlayer();
    int pAmmunition = 6;
    MediaPlayer * mediaplayer;

signals:
    void shotsFired(char);
};

#endif // PLAYER_H
