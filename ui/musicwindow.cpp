#include "include/musicwindow.h"
#include "ui_musicwindow.h"

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

void MusicWindow::on_button_exit_clicked()
{
    this->hide();
}
