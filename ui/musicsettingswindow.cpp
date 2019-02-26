#include "include/musicsettingswindow.h"
#include "ui_musicsettingswindow.h"

#include <iostream>
#include <fstream>

MusicSettingsWindow::MusicSettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicSettingsWindow)
{
    ui->setupUi(this);

    //read the json into a json object
    std::ifstream file("settings.json");
    reader.parse(file, root);

    Json::Value & val = root["music libary"];
    for (int i = 0; i < val.size(); i++)
    {
        std::string path = val[i]["path"].asString();
        ui->music_libary->addItem(QString::fromStdString(path));
    }
}

MusicSettingsWindow::~MusicSettingsWindow()
{
    delete ui;
}

void MusicSettingsWindow::on_button_add_clicked()
{
    //TODO some input...
}

void MusicSettingsWindow::on_button_delete_clicked()
{
    // get the selected item if one is selected
    QListWidgetItem *item = ui->music_libary->currentItem();
    if (item == NULL) return;
    QString directory = item->text();

    // search for the selected item in the json file and delete it
    Json::Value libary;
    Json::Value & val = root["music libary"];
    int n = 0;
    for (int i = 0; i < val.size(); i++)
    {
        std::string path = val[i]["path"].asString();
        if (directory.toStdString() != path) {
            libary[n++]["path"] = path;
        }
    }

    // clear the listView and print it again
    ui->music_libary->clear();
    for (int i = 0; i < libary.size(); i++)
    {
        std::string path = libary[i]["path"].asString();
        ui->music_libary->addItem(QString::fromStdString(path));
    }

    // change the json object, nothing will be
    // written to the json file so far
    root["music libary"] = libary;
}

void MusicSettingsWindow::on_button_settings_clicked()
{
    // write the json back to the file
    std::ofstream file_out("settings.json");
    Json::StyledWriter styledWriter;
    file_out << styledWriter.write(root);
    file_out.close();
}

void MusicSettingsWindow::on_button_back_clicked()
{
    this->hide();
}
