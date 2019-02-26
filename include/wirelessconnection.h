#ifndef WIRELESSCONNECTION_H
#define WIRELESSCONNECTION_H

#include <QWidget>
#include <jsoncpp/json/json.h>

namespace Ui {
class WirelessConnection;
}

class WirelessConnection : public QWidget
{
    Q_OBJECT

public:
    QString ip_address;
    int ip_length;
    explicit WirelessConnection(QWidget *parent = 0);
    ~WirelessConnection();

private slots:
    QString getIP(int n);
    void on_button_back_clicked();
    void on_num_0_clicked();
    void on_num_1_clicked();
    void on_num_2_clicked();
    void on_num_3_clicked();
    void on_num_4_clicked();
    void on_num_5_clicked();
    void on_num_6_clicked();
    void on_num_7_clicked();
    void on_num_8_clicked();
    void on_num_9_clicked();
    void on_button_ok_clicked();

    void on_dummy_clicked();

private:
    Ui::WirelessConnection *ui;
    Json::Reader reader;
    Json::Value root;
};

#endif // WIRELESSCONNECTION_H
