#ifndef SONGLISTWINDOW_H
#define SONGLISTWINDOW_H

#include <QWidget>
#include <string>

namespace Ui {
class SonglistWindow;
}

class SonglistWindow : public QWidget
{
    Q_OBJECT

signals:
    void playSelectedSong(std::string song);

public slots:
    void songListChanged(QString song);
    void clearList();

public:
    explicit SonglistWindow(QWidget *parent = 0);
    ~SonglistWindow();

private slots:
    void on_button_exit_clicked();

    void on_button_shuffle_clicked();

    void on_button_play_clicked();

private:
    Ui::SonglistWindow *ui;
};

#endif // SONGLISTWINDOW_H
