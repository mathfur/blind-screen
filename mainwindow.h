#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    static const int on_duration = 15*1000;
    static const int off_duration = 20*60*1000;

    Ui::MainWindow *ui;
    QTimer *on_timer,*off_timer;

private slots:
    void blind_on();
    void blind_off();
};

#endif // MAINWINDOW_H
