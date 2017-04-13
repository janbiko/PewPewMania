#ifndef LIVES_H
#define LIVES_H

#include <QGraphicsTextItem>

class Lives : public QGraphicsTextItem
{
public:
    Lives(QGraphicsItem * parent = 0);
    void decreaseLives();
    int getLives();
    void resetLives();

private:
    int lives;

};

#endif // LIVES_H
