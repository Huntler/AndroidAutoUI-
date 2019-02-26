#include "include/connectwindow.h"
#include "include/mainwindow.h"
#include "ui_connectwindow.h"

ConnectWindow::ConnectWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConnectWindow)
{
    ui->setupUi(this);
}

ConnectWindow::~ConnectWindow()
{
    delete ui;
}

void ConnectWindow::on_button_exit_clicked()
{
    this->hide();
}
