#include "include/musicwindow.h"
#include "system/clientworker.cpp"
#include "ui_musicwindow.h"
#include "include/songlistwindow.h"

#include <pthread.h>
#include <fstream>
#include <iostream>

bool bridge_running = false;

//
// UI stuff starts here, read below
//

SonglistWindow * songlist;
ClientWorker * clientWorker = new ClientWorker;

std::string song_name = "";

MusicWindow::MusicWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicWindow)
{
    ui->setupUi(this);

    // add connections between slots and signals for the bridge communication
    if (true)
    {
        clientWorker->moveToThread(&worker);

        // set up connections to the bridge
        connect(&worker, SIGNAL(finished()), clientWorker, SLOT(deleteLater()));
        connect(this, SIGNAL(operate(QString)), clientWorker, SLOT(awaitBridge(QString)));
        connect(clientWorker, SIGNAL(gotResult(QString)), this, SLOT(handleResults(QString)));

        worker.start();

        // initialize the song libary
        //read the json into a json object
        std::ifstream file("settings.json");
        reader.parse(file, root);

        Json::Value &lib = root["music libary"];
        for (int i = 0; i < lib.size(); i++)
        {
            std::string path = lib[i]["path"].asString();
            this->operate(QString::fromStdString("add_folder::" + path));
        }

        bridge_running = true;
    }

    songlist = new SonglistWindow;

    // add connections between slots and signals
    QObject::connect(this, SIGNAL(addSongToList(QString)), songlist, SLOT(songListChanged(QString)));
    QObject::connect(this, SIGNAL(clearList()), songlist, SLOT(clearList()));
    QObject::connect(songlist, SIGNAL(playSelectedSong(std::string)), this, SLOT(runCommand(std::string)));

    // set the ui
    ui->song_title->setText(QString::fromStdString(song_name));
}

MusicWindow::~MusicWindow()
{
    delete ui;
}

// helper method that splits a string into a vector / list
std::vector<std::string> split(std::string input, std::string delimitter)
{
    std::vector<std::string> list;
    size_t pos = 0;
    std::string token;

    while ((pos = input.find(delimitter)) != std::string::npos) {
        token = input.substr(0, pos);
        list.push_back(token);
        input.erase(0, pos + delimitter.length());
    }

    list.push_back(input);

    return list;
}

void MusicWindow::handleResults(QString s)
{
    std::vector<std::string> line = split(s.toStdString(), "::");

    if (line[0] == "current song")
    {
        song_name = line[1];
        ui->song_title->setText(QString::fromStdString(line[1]));
    }
    else if (line[0] == "songs")
    {
        for (std::vector<std::string>::iterator i = line.begin(); i != line.end(); ++i)
        {
            if (*i != "songs")
                this->addSongToList((QString::fromStdString(*i)));
        }
        songlist->showFullScreen();
    }
}

// command slot function
void MusicWindow::runCommand(std::string cmd)
{
    this->operate(QString::fromStdString(cmd));
}

void MusicWindow::on_tap_area_tophalf_clicked()
{    
    this->clearList();
    this->operate(QString::fromStdString("get_songs"));
}

void MusicWindow::on_button_play_clicked()
{
    this->operate(QString::fromStdString("play"));
}

void MusicWindow::on_button_prev_clicked()
{
    this->operate(QString::fromStdString("prev"));
}

void MusicWindow::on_button_next_clicked()
{
    this->operate(QString::fromStdString("skip"));
}

void MusicWindow::on_button_exit_clicked()
{
    this->hide();
}
