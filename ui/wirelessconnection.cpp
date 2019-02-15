#include "include/wirelessconnection.h"
#include "include/mainwindow.h"
#include "ui_wirelessconnection.h"

#include <sstream>
#include <iostream>

QString _ip_address;
int _ip_length = 0;

WirelessConnection::WirelessConnection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WirelessConnection)
{
    ui->setupUi(this);

    // if there was a ip typed in, set it to the ui elements again
    if (_ip_length > 0) {
        ip_address = _ip_address;
        ip_length = _ip_length;
        ui->num_ip->setText(ip_address);
    }
}

WirelessConnection::~WirelessConnection()
{
    delete ui;
}

void WirelessConnection::on_button_back_clicked()
{
    // save the current ip
    _ip_address = ip_address;
    _ip_length = ip_length;
    this->hide();
}

void WirelessConnection::on_button_ok_clicked()
{
    // clear the current ip
    ip_address.clear();
    ip_length = 0;
    ui->num_ip->setText(ip_address);
}

QString WirelessConnection::getIP(int n) {
    // if the ip length is not over 12, add the number taht was clicked
    if (ip_length != 12) {
        ip_address.append(QString::number(n));
        ip_length++;

        if (ip_length % 3 == 0 && ip_length < 12) {
            ip_address.append(".");
        }
    }


    return ip_address;
}

void WirelessConnection::on_num_0_clicked()
{
    ui->num_ip->setText(getIP(0));
}

void WirelessConnection::on_num_1_clicked()
{
    ui->num_ip->setText(getIP(1));
}

void WirelessConnection::on_num_2_clicked()
{
    ui->num_ip->setText(getIP(2));
}

void WirelessConnection::on_num_3_clicked()
{
    ui->num_ip->setText(getIP(3));
}

void WirelessConnection::on_num_4_clicked()
{
    ui->num_ip->setText(getIP(4));
}

void WirelessConnection::on_num_5_clicked()
{
    ui->num_ip->setText(getIP(5));
}

void WirelessConnection::on_num_6_clicked()
{
    ui->num_ip->setText(getIP(6));
}

void WirelessConnection::on_num_7_clicked()
{
    ui->num_ip->setText(getIP(7));
}

void WirelessConnection::on_num_8_clicked()
{
    ui->num_ip->setText(getIP(8));
}

void WirelessConnection::on_num_9_clicked()
{
    ui->num_ip->setText(getIP(9));
}


void WirelessConnection::on_dummy_clicked()
{
    // TODO: try to connect over wifi
}
