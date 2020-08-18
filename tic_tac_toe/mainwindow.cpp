#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game_screen = new gameScreen();
    ai_game_screen = new aiGameScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    qDebug() << "one_player";
    this->hide();
    ai_game_screen->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug() << "two_players";
    this->hide();
    game_screen->show();

}

void MainWindow::on_pushButton_3_clicked()
{
    qDebug() << "network";
    ui->label->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
}
