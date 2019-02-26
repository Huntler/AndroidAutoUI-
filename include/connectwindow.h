#ifndef CONNECTWINDOW_H
#define CONNECTWINDOW_H

#include <QWidget>

namespace Ui {
class ConnectWindow;
}

class ConnectWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectWindow(QWidget *parent = 0);
    ~ConnectWindow();

private slots:
    void on_button_exit_clicked();

private:
    Ui::ConnectWindow *ui;
};

#endif // CONNECTWINDOW_H
