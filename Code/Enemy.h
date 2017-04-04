#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsScene>
#include <QObject>

class Enemy : public QObject
{
    Q_OBJECT
public:
    Enemy(QObject *parent = 0);
};

#endif // ENEMY_H
