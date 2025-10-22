#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setText("test");
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Button_play_clicked()
{
    play = new player;
    this->hide();
    play->show();
}
