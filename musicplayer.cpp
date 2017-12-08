#include "musicplayer.h"
#include <QDebug>

MusicPlayer::MusicPlayer()
{
    player = new QMediaPlayer();
    QObject::connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(new_one(qint64)));
}

void MusicPlayer::playTheSong(QString path)
{
    player->setMedia(QUrl::fromLocalFile(path));
}

void MusicPlayer::stopPlaying()
{
    player->stop();
}

void MusicPlayer::run()
{

}

void MusicPlayer::new_one(qint64 dtdt)
{
    if (dtdt)
    {
        qsrand(QTime::currentTime().msec());
        int pos = qrand() % (dtdt / 1000);
        if (pos < 10)
            pos += 10;
        else if (pos > dtdt / 1000 - 10)
            pos -= 10;
        player->setPosition((pos - 10) * 1000);
        player->play();
    }
}
