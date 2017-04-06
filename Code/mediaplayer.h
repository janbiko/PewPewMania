#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QObject>
#include <QMediaPlaylist>
#include <QMediaPlayer>

class MediaPlayer : public QObject
{
    Q_OBJECT
public:
    MediaPlayer();
    void playBackgroundMusic();

private:
    QMediaPlaylist * mpBGMusicPlaylist;
    QMediaPlayer * mpBGMusic;

};

#endif // MEDIAPLAYER_H
