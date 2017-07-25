#include "Ammo.h"

Ammo::Ammo(int gameWidth): QObject(), QGraphicsPixmapItem()
{
    aGameWidth = gameWidth;
    setPixmap(QPixmap("../assets/img/ammo/ammo6"));
    setPos(aGameWidth / 2 - aWidth, y() + aYOffset);
    this->setScale(1.5);
}

void Ammo::decreaseAmmo()
{
    if(aAmmo == 6) {
        setPixmap(QPixmap("../assets/img/ammo/ammo5"));
        --aAmmo;
    } else if (aAmmo == 5) {
        setPixmap(QPixmap("../assets/img/ammo/ammo4"));
        --aAmmo;
    } else if (aAmmo == 4) {
        setPixmap(QPixmap("../assets/img/ammo/ammo3"));
        --aAmmo;
    } else if (aAmmo == 3) {
        setPixmap(QPixmap("../assets/img/ammo/ammo2"));
        --aAmmo;
    } else if (aAmmo == 2) {
        setPixmap(QPixmap("../assets/img/ammo/ammo1"));
        --aAmmo;
    } else if (aAmmo == 1) {
        setPixmap(QPixmap("../assets/img/ammo/ammo0"));
        --aAmmo;
    }
}

void Ammo::reloadAmmo()
{
    aAmmo = 6;
    setPixmap(QPixmap("../assets/img/ammo/ammo6"));
}
