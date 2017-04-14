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
    if(ammo == 6) {
        setPixmap(QPixmap("../assets/img/ammo/ammo5"));
        --ammo;
    } else if (ammo == 5) {
        setPixmap(QPixmap("../assets/img/ammo/ammo4"));
        --ammo;
    } else if (ammo == 4) {
        setPixmap(QPixmap("../assets/img/ammo/ammo3"));
        --ammo;
    } else if (ammo == 3) {
        setPixmap(QPixmap("../assets/img/ammo/ammo2"));
        --ammo;
    } else if (ammo == 2) {
        setPixmap(QPixmap("../assets/img/ammo/ammo1"));
        --ammo;
    } else if (ammo == 1) {
        setPixmap(QPixmap("../assets/img/ammo/ammo0"));
        --ammo;
    }
}

void Ammo::reloadAmmo()
{
    ammo = 6;
    setPixmap(QPixmap("../assets/img/ammo/ammo6"));
}
