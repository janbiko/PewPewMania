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
    void playShootingSound();
    void playReloadSound();

private:
    // background music
    QMediaPlaylist * mpBGMusicPlaylist;
    QMediaPlayer * mpBGMusic;

    // shooting sound
    QMediaPlaylist * mpShootingSoundPlaylist;
    QMediaPlayer * mpShootingSound;

    // reload sound
    QMediaPlaylist * mpReloadSoundPlaylist;
    QMediaPlayer * mpReloadSound;

};

#endif // MEDIAPLAYER_H
