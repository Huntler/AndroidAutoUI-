#ifndef MUSICWINDOW_H
#define MUSICWINDOW_H

#include <QWidget>
#include <QThread>
#include <string>
#include <jsoncpp/json/json.h>

namespace Ui {
class MusicWindow;
}

class MusicWindow : public QWidget
{
    Q_OBJECT
    QThread worker;

public:
    explicit MusicWindow(QWidget *parent = 0);
    ~MusicWindow();

signals:
    // necessary for songlistwindow
    void addSongToList(QString song);
    void clearList();

    // necessary for the clientworker
    void operate(QString cmd);

public slots:
    // necessary for songlistwindow
    void runCommand(std::string cmd);

    // necessary for the clientworker
    void handleResults(QString res);

private slots:
    void on_button_exit_clicked();

    void on_tap_area_tophalf_clicked();

    void on_button_play_clicked();

    void on_button_prev_clicked();

    void on_button_next_clicked();

private:
    Ui::MusicWindow *ui;
    Json::Reader reader;
    Json::Value root;
};

#endif // MUSICWINDOW_H
