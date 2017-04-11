#ifndef AMMO_H
#define AMMO_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Ammo: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Ammo();
    void decreaseAmmo();
    void reloadAmmo();

private:
    int ammo = 6;

};

#endif // AMMO_H
