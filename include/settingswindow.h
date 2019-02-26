#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>
#include <jsoncpp/json/json.h>

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = 0);
    ~SettingsWindow();

private slots:

    void on_button_back_clicked();

    void on_button_restore_clicked();

    void on_hotspot_settings_clicked();

    void on_music_settings_clicked();

    void on_button_settings_clicked();

private:
    Ui::SettingsWindow *ui;
    Json::Reader reader;
    Json::Value root;
};

#endif // SETTINGSWINDOW_H
