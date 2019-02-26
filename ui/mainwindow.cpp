#include "include/mainwindow.h"
#include "include/settingswindow.h"
#include "include/connectwindow.h"
#include "include/wirelessconnection.h"
#include "include/musicwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_car_clicked()
{
    ConnectWindow *widget = new ConnectWindow;
    widget->showFullScreen();
}

void MainWindow::on_button_recent_clicked()
{
    WirelessConnection *widget = new WirelessConnection;
    widget->showFullScreen();
}

void MainWindow::on_button_close_clicked()
{
    close();
}


void MainWindow::on_button_settings_clicked()
{
    SettingsWindow *widget = new SettingsWindow;
    widget->showFullScreen();
}


void MainWindow::on_button_musicapp_clicked()
{
    MusicWindow *widget = new MusicWindow;
    widget->showFullScreen();
}
