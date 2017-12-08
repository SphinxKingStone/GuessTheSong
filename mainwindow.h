#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "musicplayer.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void showSongName(QString name);
    void tick();

    void on_pushButton_2_clicked();

private:
    MusicPlayer player;
    Ui::MainWindow *ui;
    QTimer timer;
    QString path;
    QString song_file_name = "";
};

#endif // MAINWINDOW_H
