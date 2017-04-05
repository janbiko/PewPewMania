#include "Enemy.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <stdlib.h>

Enemy::Enemy(): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap("../assets/img/EnemyModel.png"));

    // random Position
    int randomY = rand() % 600;
    setPos(randomSpawnSide(), randomY);

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    if(eSpawnSide == 'l') {
        moveBy(10, 0);
    }
    else if(eSpawnSide == 'r'){
        moveBy(-10, 0);
    }
    if(x()> 660){
        scene()->removeItem(this);
        delete this;
    }
    else if(x()<-60){
        scene()->removeItem(this);
        delete this;
    }
}

int Enemy::randomSpawnSide()
{
    int randomSpawn = rand() % 2;
    if(randomSpawn == 0){
        eSpawnSide = 'l';
        return -50;
    }
    else{
        eSpawnSide = 'r';
        QTransform transform;
        transform.rotate(180);
        this->setTransform(transform);
        return 650;
    }
}







