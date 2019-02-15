#include "include/musicwindow.h"
#include "ui_musicwindow.h"

#include <pthread.h>

MusicWindow::MusicWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicWindow)
{
    ui->setupUi(this);
}

MusicWindow::~MusicWindow()
{
    delete ui;
}

void * AsyncCommand(void *)
{
    system("echo 'hi'");
}

void MusicWindow::on_button_exit_clicked()
{
    this->hide();
}

void MusicWindow::on_tap_area_tophalf_clicked()
{
    // change to song queue here
}

void MusicWindow::on_button_play_clicked()
{
    pthread_t thread;
    pthread_create(&thread, NULL, AsyncCommand, NULL);

    pthread_detach(thread);
}

void MusicWindow::on_button_prev_clicked()
{
    // play previous song
}

void MusicWindow::on_button_next_clicked()
{
    // play next song
}
