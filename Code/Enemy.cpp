#include "Enemy.h"
#include "Player.h"
#include <QList>

extern Lives * lives;

Enemy::Enemy(int gameWidth, int gameHeigth): QObject(), QGraphicsPixmapItem()
{
    eGameWidth = gameWidth;
    eGameHeight = gameHeigth;

    // random Position
    int randomY = rand() % gameHeigth;
    setPos(randomSpawnSide(), randomY);

    eMovementTimer = new QTimer(this);
    connect(eMovementTimer, SIGNAL(timeout()), this, SLOT(move()));
    eMovementTimer->start(1000/144);

    eAnimationTimer = new QTimer(this);
    if(eSpawnSide == 'l') {
        connect(eAnimationTimer, SIGNAL(timeout()), this, SLOT(animateRightWalkingEnemy()));
        eAnimationTimer->start(120);
    } else {
        connect(eAnimationTimer, SIGNAL(timeout()), this, SLOT(animateLeftWalkingEnemy()));
        eAnimationTimer->start(120);
    }
}

void Enemy::move()
{
    if (gameOver()) return;
    if(!checkForPlayerCollision()) {
        if(eSpawnSide == 'l') {
            moveBy(eMovementSpeed, 0);
        }
        else if(eSpawnSide == 'r'){
            moveBy(-eMovementSpeed, 0);
        }
        if(x() > eGameWidth + eWorldBoundOffset){
            scene()->removeItem(this);
            delete this;
        }
        else if(x() < 0 - eWorldBoundOffset){
            scene()->removeItem(this);
            delete this;
        }
    }
}

void Enemy::animateLeftWalkingEnemy()
{
    if(eCurrentFrame == 4) eCurrentFrame = 0;
    if(eCurrentFrame == 0) {
        setPixmap(QPixmap("../assets/img/enemy/EnemyWalkLeft0.png"));
        ++eCurrentFrame;
    } else if(eCurrentFrame == 1) {
        setPixmap(QPixmap("../assets/img/enemy/EnemyWalkLeft1.png"));
        ++eCurrentFrame;
    } else if(eCurrentFrame == 2) {
        setPixmap(QPixmap("../assets/img/enemy/EnemyWalkLeft2.png"));
        ++eCurrentFrame;
    } else if(eCurrentFrame == 3) {
        setPixmap(QPixmap("../assets/img/enemy/EnemyWalkLeft3.png"));
        ++eCurrentFrame;
    }
}

void Enemy::animateRightWalkingEnemy()
{
    if(eCurrentFrame == 4) eCurrentFrame = 0;
    if(eCurrentFrame == 0) {
        setPixmap(QPixmap("../assets/img/enemy/EnemyWalkRight0.png"));
        ++eCurrentFrame;
    } else if(eCurrentFrame == 1) {
        setPixmap(QPixmap("../assets/img/enemy/EnemyWalkRight1.png"));
        ++eCurrentFrame;
    } else if(eCurrentFrame == 2) {
        setPixmap(QPixmap("../assets/img/enemy/EnemyWalkRight2.png"));
        ++eCurrentFrame;
    } else if(eCurrentFrame == 3) {
        setPixmap(QPixmap("../assets/img/enemy/EnemyWalkRight3.png"));
        ++eCurrentFrame;
    }
}

int Enemy::randomSpawnSide()
{
    int randomSpawn = rand() % 2;
    if(randomSpawn == 0){
        eSpawnSide = 'l';
        return 0 - eWorldBoundOffset;
    }
    else{
        eSpawnSide = 'r';
        return eGameWidth + eWorldBoundOffset;
    }
}

bool Enemy::checkForPlayerCollision()
{
    colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); ++i) {
        if(typeid(*(colliding_items[i])) == typeid(Player)) {
            lives->decreaseLives();
            scene()->removeItem(this);
            delete this;
            return true;
        }
    }
    return false;
}

bool Enemy::gameOver()
{
    if (lives->getLives() == 0) {
        scene()->removeItem(this);
        delete this;
        return true;
    }
    return false;
}







