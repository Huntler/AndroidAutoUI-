#include "include/songlistwindow.h"
#include "ui_songlistwindow.h"
#include "include/musicwindow.h"

#include <iostream>

SonglistWindow::SonglistWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SonglistWindow)
{
    ui->setupUi(this);
}

SonglistWindow::~SonglistWindow()
{
    delete ui;
}

void SonglistWindow::songListChanged(QString song)
{
    ui->song_list->addItem(song);
}

void SonglistWindow::clearList()
{
    ui->song_list->clear();
}

void SonglistWindow::on_button_exit_clicked()
{
    this->hide();
}

void SonglistWindow::on_button_shuffle_clicked()
{
    std::string cmd = "shuffle";
    this->playSelectedSong(cmd);

    this->hide();
}

void SonglistWindow::on_button_play_clicked()
{
    // Get the pointer to the currently selected item.
    QListWidgetItem *item = ui->song_list->currentItem();

    std::string cmd = "play::" + item->text().toStdString();
    this->playSelectedSong(cmd);

    this->hide();
}
