#ifndef MUSICSETTINGSWINDOW_H
#define MUSICSETTINGSWINDOW_H

#include <QWidget>
#include <jsoncpp/json/json.h>

namespace Ui {
class MusicSettingsWindow;
}

class MusicSettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MusicSettingsWindow(QWidget *parent = 0);
    ~MusicSettingsWindow();

private slots:
    void on_button_add_clicked();

    void on_button_delete_clicked();

    void on_button_settings_clicked();

    void on_button_back_clicked();

private:
    Ui::MusicSettingsWindow *ui;
    Json::Reader reader;
    Json::Value root;
};

#endif // MUSICSETTINGSWINDOW_H
