#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    timer = new QTimer(this);

    connect( timer, SIGNAL(timeout()),
         this, SLOT(blind_off()) );

    timer->start(15*1000);

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::blind_off()
{
    timer->stop();
    this->hide();
}
