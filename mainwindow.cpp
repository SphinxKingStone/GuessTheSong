#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(&player, SIGNAL(finished(QString)), this, SLOT(showSongName(QString)));
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(tick()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    WIN32_FIND_DATA FindFileData;
    HANDLE hf;
    int file_count = 0;
    path = "F:\\Музыка\\Аудиозаписи Максима Мишакова\\";

    hf=FindFirstFile((const wchar_t*) QString(path+"*").utf16(), &FindFileData);
    if (hf!=INVALID_HANDLE_VALUE)
    {
        do
        {
            if (!(QString::fromWCharArray(FindFileData.cFileName) == "..") && !(QString::fromWCharArray(FindFileData.cFileName) == "."))
                file_count++;

        } while (FindNextFile(hf,&FindFileData)!=0);

        FindClose(hf);
    }


    hf=FindFirstFile((const wchar_t*) QString(path+"*").utf16(), &FindFileData);
    if (hf!=INVALID_HANDLE_VALUE)
    {
        qsrand(QTime::currentTime().msec());
        int stop_point = 2;
        stop_point += qrand()%file_count;
        int i = 0;
        do
        {
            FindNextFile(hf,&FindFileData);
            i++;
        } while (i < stop_point);

        song_file_name = QString::fromWCharArray(FindFileData.cFileName);

        path += song_file_name;

        FindClose(hf);
    }

    player.playTheSong(path);
    player.start();
    timer.start(10000);
    ui->pushButton->setEnabled(false);
}

void MainWindow::showSongName(QString name)
{
    qDebug() << name;
}

void MainWindow::tick()
{
    ui->pushButton->setEnabled(true);
    timer.stop();
    player.stopPlaying();
    ui->label->setText("Песня была - " + song_file_name);
/*
    qsrand(QTime::currentTime().msec());
    path.chop(5);
    qDebug() << path;

    path += QString::number(qrand()%6) + ".mp3";
    player.playTheSong(path);
    player.start();*/
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton->setEnabled(true);
}
