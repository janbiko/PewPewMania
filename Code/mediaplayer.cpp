#include "Mediaplayer.h"

MediaPlayer::MediaPlayer() : QObject()
{
    // background music
    mpBGMusicPlaylist = new QMediaPlaylist();
    mpBGMusicPlaylist->addMedia(QUrl("../assets/snd/background_music.wav"));
    mpBGMusicPlaylist->setPlaybackMode(QMediaPlaylist::Loop);
    mpBGMusic = new QMediaPlayer();
    mpBGMusic->setPlaylist(mpBGMusicPlaylist);

    // shooting sound
    mpShootingSoundPlaylist = new QMediaPlaylist();
    mpShootingSoundPlaylist->addMedia(QUrl("../assets/snd/shoot.mp3"));
    mpShootingSound = new QMediaPlayer();
    mpShootingSound->setPlaylist(mpShootingSoundPlaylist);

    // reload sound
    mpReloadSoundPlaylist = new QMediaPlaylist();
    mpReloadSoundPlaylist->addMedia(QUrl("../assets/snd/reload.mp3"));
    mpReloadSound = new QMediaPlayer();
    mpReloadSound->setPlaylist(mpReloadSoundPlaylist);

    // hit sound
    mpHitSoundPlaylist = new QMediaPlaylist();
    mpHitSoundPlaylist->addMedia(QUrl("../assets/snd/hit.mp3"));
    mpHitSound = new QMediaPlayer();
    mpHitSound->setPlaylist(mpHitSoundPlaylist);
}

void MediaPlayer::playBackgroundMusic()
{    
    mpBGMusic->play();
}

void MediaPlayer::playShootingSound()
{
    mpShootingSound->stop();
    mpShootingSound->play();
}

void MediaPlayer::playReloadSound()
{
    mpReloadSound->stop();
    mpReloadSound->play();
}

void MediaPlayer::playHitSound()
{
    mpHitSound->stop();
    mpHitSound->play();
}
