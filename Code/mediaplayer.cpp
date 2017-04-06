#include "mediaplayer.h"
#include <QUrl>


MediaPlayer::MediaPlayer() : QObject()
{
    mpBGMusicPlaylist = new QMediaPlaylist();
    mpBGMusicPlaylist->addMedia(QUrl("../assets/snd/background_music.wav"));
    //mpBGMusicPlaylist->setPlaybackMode(QMediaPlaylist::loop);
}

void MediaPlayer::playBackgroundMusic()
{
    mpBGMusic = new QMediaPlayer();
    mpBGMusic->setPlaylist(mpBGMusicPlaylist);
    mpBGMusic->play();
}
