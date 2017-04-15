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
#include "Mediaplayer.h"

extern Ammo * ammo;

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(int gameWidth, int gameHeight);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void movePlayer();
    void updatePlayer();
    void resetPlayer();

public slots:
    void animateRightWalkingPlayer();
    void animateLeftWalkingPlayer();

private:
    void initValues();
    void shoot();
    void resetKeys();
    void resetAmmo();
    char pFacingSide = 'r';
    int pHeight = 37;
    int pWidth = 36;
    int pX, pY;
    int pSpeed = 4;
    bool keyLeftPressed, keyRightPressed, keyUpPressed, keyDownPressed;
    Bullet * bullet;
    QTimer * bulletTimer;
    int pBulletYOffset = 21;
    int pBulletRXOffset = 35;
    int pBulletLXOffset = -5;
    int pCurrentFrame = 0;
    QTimer * pAnimationTimer;
    void animatePlayer();
    int pAmmunition = 6;
    int pGameWidth;
    int pGameHeight;
    MediaPlayer * mediaplayer;

signals:
    void shotsFired(char);
};

#endif // PLAYER_H
