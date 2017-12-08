#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QUrl>
#include <QMediaPlayer>
#include <windows.h>
#include <QTime>
#include <QThreadPool>

class MusicPlayer: public QThread
{
    Q_OBJECT
public:
    MusicPlayer();
//    ~MusicPlayer();

    void playTheSong(QString path);
    void stopPlaying();

signals:
    finished(QString name);
    gogo();

protected:
    void run() override;

private slots:
    void new_one(qint64 dtdt);

private:
    QMediaPlayer * player;
    QString path_str;
    int durat;
};

#endif // MUSICPLAYER_H
