#include "include/settingswindow.h"
#include "include/mainwindow.h"
#include "include/musicsettingswindow.h"
#include "ui_settingswindow.h"

#include <fstream>
#include <iostream>

MusicSettingsWindow * musicSettings;

SettingsWindow::SettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    //read the json into a json object
    std::ifstream file("settings.json");
    reader.parse(file, root);

    ui->sound_slider->setValue(root["volume"].asUInt());
    ui->brighness_slider->setValue(root["brightness"].asUInt());

}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_button_back_clicked()
{
    this->hide();
}

void SettingsWindow::on_button_restore_clicked()
{
    ui->sound_slider->setValue(root["volume"].asUInt());
    ui->brighness_slider->setValue(root["brightness"].asUInt());
}

void SettingsWindow::on_hotspot_settings_clicked()
{

}

void SettingsWindow::on_music_settings_clicked()
{
    musicSettings = new MusicSettingsWindow;
    musicSettings->showFullScreen();
}

void SettingsWindow::on_button_settings_clicked()
{
    // save the settings here
    root["brightness"] = ui->brighness_slider->value();
    root["volume"] = ui->sound_slider->value();

    // write the json back to the file
    std::ofstream file_out("settings.json");
    Json::StyledWriter styledWriter;
    file_out << styledWriter.write(root);
    file_out.close();
}
