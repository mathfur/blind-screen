#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    on_timer = new QTimer(this);
    off_timer = new QTimer(this);

    connect( on_timer, SIGNAL(timeout()), this, SLOT(blind_on()) );
    connect( off_timer, SIGNAL(timeout()), this, SLOT(blind_off()) );

    this->blind_off();

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::blind_off()
{
    off_timer->stop();
    this->hide();

    // 20分後にblind_onを実行
    on_timer->start(off_duration);
}

void MainWindow::blind_on()
{
    on_timer->stop();
    this->showFullScreen();

    // 15秒後にblind_offを実行
    off_timer->start(on_duration);
}
