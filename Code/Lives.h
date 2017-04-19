#ifndef LIVES_H
#define LIVES_H

#include <QGraphicsTextItem>
#include <QFont>
#include <Mediaplayer.h>

class Lives : public QGraphicsTextItem
{
public:
    Lives(int gameWidth);
    void decreaseLives();
    int getLives();
    void resetLives();

private:
    int lLives;
    int lGameWidth;
    int lLivesXOffset = 100;
    int lFontSize = 18;
    MediaPlayer * mediaPlayer;

};

#endif // LIVES_H
