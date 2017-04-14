#ifndef AMMO_H
#define AMMO_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Ammo: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Ammo(int gameWidth);
    void decreaseAmmo();
    void reloadAmmo();

private:
    int ammo = 6;
    int aWidth = 61;
    int aGameWidth;
    int aYOffset = 10;
};

#endif // AMMO_H
