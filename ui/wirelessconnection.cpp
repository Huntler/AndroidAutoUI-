#include "include/wirelessconnection.h"
#include "include/mainwindow.h"
#include "ui_wirelessconnection.h"

#include <fstream>
#include <iostream>
#include <sstream>

WirelessConnection::WirelessConnection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WirelessConnection)
{
    ui->setupUi(this);

    //read the json into a json object
    std::ifstream file("settings.json");
    reader.parse(file, root);

    ui->num_ip->setText(QString::fromStdString(root["wireless connection"].asString()));

}

WirelessConnection::~WirelessConnection()
{
    delete ui;
}

void WirelessConnection::on_button_back_clicked()
{
    this->hide();
}

void WirelessConnection::on_button_ok_clicked()
{
    // save the settings here
    root["wireless connection"] = ip_address.toStdString();

    // write the json back to the file
    std::ofstream file_out("settings.json");
    Json::StyledWriter styledWriter;
    file_out << styledWriter.write(root);
    file_out.close();
}

QString WirelessConnection::getIP(int n) {
    // if the ip length is not over 12, add the number which was clicked
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
