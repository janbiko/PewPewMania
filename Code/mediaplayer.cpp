#include "mediaplayer.h"
#include <QUrl>


MediaPlayer::MediaPlayer() : QObject()
{
    // background music
    mpBGMusicPlaylist = new QMediaPlaylist();
    mpBGMusicPlaylist->addMedia(QUrl("../assets/snd/background_music.wav"));
    mpBGMusicPlaylist->setPlaybackMode(QMediaPlaylist::Loop);

    // shooting sound
    mpShootingSoundPlaylist = new QMediaPlaylist();
    mpShootingSoundPlaylist->addMedia(QUrl("../assets/snd/shoot.mp3"));

    // reload sound
    mpReloadSoundPlaylist = new QMediaPlaylist();
    mpReloadSoundPlaylist->addMedia(QUrl("../assets/snd/reload.mp3"));
}

void MediaPlayer::playBackgroundMusic()
{
    mpBGMusic = new QMediaPlayer();
    mpBGMusic->setPlaylist(mpBGMusicPlaylist);
    mpBGMusic->play();
}

void MediaPlayer::playShootingSound()
{
    mpShootingSound = new QMediaPlayer();
    mpShootingSound->setPlaylist(mpShootingSoundPlaylist);
    mpShootingSound->play();
}

void MediaPlayer::playReloadSound()
{
    mpReloadSound = new QMediaPlayer();
    mpReloadSound->setPlaylist(mpReloadSoundPlaylist);
    mpReloadSound->play();
}
