#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void movePlayer();
    void updatePlayer();
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
signals:
    void shotsFired(char);
};

#endif // PLAYER_H
