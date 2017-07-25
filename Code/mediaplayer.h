#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QObject>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QUrl>

class MediaPlayer : public QObject
{
    Q_OBJECT
public:
    MediaPlayer();
    void playBackgroundMusic();
    void playShootingSound();
    void playReloadSound();
    void playHitSound();

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

    // hit sound
    QMediaPlaylist * mpHitSoundPlaylist;
    QMediaPlayer * mpHitSound;

};

#endif // MEDIAPLAYER_H
