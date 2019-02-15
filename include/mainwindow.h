#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_button_close_clicked();

    void on_button_car_clicked();

    void on_button_settings_clicked();

    void on_button_recent_clicked();

    void on_button_musicapp_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
