#include "include/settingswindow.h"
#include "include/mainwindow.h"
#include "include/system/SettingsManager.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    SettingsManager manager;
    manager.readFile();

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
    ui->sound_slider->setValue(75);
    ui->brighness_slider->setValue(255);
}

void SettingsWindow::on_hotspot_settings_clicked()
{

}

void SettingsWindow::on_music_settings_clicked()
{

}

void SettingsWindow::on_button_settings_clicked()
{

}
