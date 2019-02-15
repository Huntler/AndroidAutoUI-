#ifndef MUSICWINDOW_H
#define MUSICWINDOW_H

#include <QWidget>

namespace Ui {
class MusicWindow;
}

class MusicWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MusicWindow(QWidget *parent = 0);
    ~MusicWindow();

private slots:
    void on_button_exit_clicked();

    void on_tap_area_tophalf_clicked();

    void on_button_play_clicked();

    void on_button_prev_clicked();

    void on_button_next_clicked();

private:
    Ui::MusicWindow *ui;
};

#endif // MUSICWINDOW_H
