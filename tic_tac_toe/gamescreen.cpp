#include "gamescreen.h"
#include "ui_gamescreen.h"

gameScreen::gameScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gameScreen)
{
    ui->setupUi(this);
}

gameScreen::~gameScreen()
{
    delete ui;
}
void gameScreen::is_winning()
{
    if((game_area[1-1] > 5 && game_area[2-1] > 5 && game_area[3-1] > 5) ||
       (game_area[4-1] > 5 && game_area[5-1] > 5 && game_area[6-1] > 5) ||
       (game_area[7-1] > 5 && game_area[8-1] > 5 && game_area[9-1] > 5) ||
       (game_area[1-1] > 5 && game_area[4-1] > 5 && game_area[7-1] > 5) ||
       (game_area[2-1] > 5 && game_area[5-1] > 5 && game_area[8-1] > 5) ||
       (game_area[3-1] > 5 && game_area[6-1] > 5 && game_area[9-1] > 5) ||
       (game_area[1-1] > 5 && game_area[5-1] > 5 && game_area[9-1] > 5) ||
       (game_area[3-1] > 5 && game_area[5-1] > 5 && game_area[7-1] > 5)
           )
    {

        QMessageBox msgBox;
        if(turn)
            msgBox.setText("Wygrywa gracz kolko");
        else
            msgBox.setText("Wygrywa gracz krzyżyk");
        msgBox.exec();
        QApplication::exit();
    }
    if(game_area[0] < 5 &&
       game_area[1] < 5 &&
       game_area[2] < 5 &&
       game_area[3] < 5 &&
       game_area[4] < 5 &&
       game_area[5] < 5 &&
       game_area[6] < 5 &&
       game_area[7] < 5 &&
       game_area[8] < 5 )
    {
        QMessageBox msgBox;
        msgBox.setText("Remis");
        msgBox.exec();
        QApplication::exit();
    }
}
void gameScreen::on_btn1_clicked()
{
    if(game_area[1-1] < 5)
    {
        if(turn)
        {
            ui->btn1->setText("X");
            game_area[1-1] = 10;
        }
        else
        {
            ui->btn1->setText("O");
            game_area[1-1] = 30;
        }
        turn = !turn;
    }
    is_winning();
}

void gameScreen::on_btn2_clicked()
{
    if(game_area[2-1] < 5)
    {
        if(turn)
        {
            ui->btn2->setText("X");
            game_area[2-1] = 10;
        }
        else
        {
            ui->btn2->setText("O");
            game_area[2-1] = 30;
        }
        turn = !turn;
    }
    is_winning();
}

void gameScreen::on_btn3_clicked()
{

    if(game_area[3-1] < 5)
    {
        if(turn)
        {
            ui->btn3->setText("X");
            game_area[3-1] = 10;
        }
        else
        {
            ui->btn3->setText("O");
            game_area[3-1] = 30;
        }
        turn = !turn;
    }
    is_winning();
}

void gameScreen::on_btn4_clicked()
{
    if(game_area[4-1] < 5)
    {
        if(turn)
        {
            ui->btn4->setText("X");
            game_area[4-1] = 10;
        }
        else
        {
            ui->btn4->setText("O");
            game_area[4-1] = 30;
        }
        turn = !turn;
    }
    is_winning();
}

void gameScreen::on_btn5_clicked()
{
    if(game_area[5-1] < 5)
    {
        if(turn)
        {
            ui->btn5->setText("X");
            game_area[5-1] = 10;
        }
        else
        {
            ui->btn5->setText("O");
            game_area[5-1] = 30;
        }
        turn = !turn;
    }
    is_winning();
}

void gameScreen::on_btn6_clicked()
{
    if(game_area[6-1] < 5)
    {
        if(turn)
        {
            ui->btn6->setText("X");
            game_area[6-1] = 10;
        }
        else
        {
            ui->btn6->setText("O");
            game_area[6-1] = 30;
        }
        turn = !turn;
    }
    is_winning();
}
void gameScreen::on_btn7_clicked()
{
    if(game_area[7-1] < 5)
    {
        if(turn)
        {
            ui->btn7->setText("X");
            game_area[7-1] = 10;
        }
        else
        {
            ui->btn7->setText("O");
            game_area[7-1] = 30;
        }
        turn = !turn;
    }
    is_winning();
}

void gameScreen::on_btn8_clicked()
{
    if(game_area[8-1] < 5)
    {
        if(turn)
        {
            ui->btn8->setText("X");
            game_area[8-1] = 10;
        }
        else
        {
            ui->btn8->setText("O");
            game_area[8-1] = 30;
        }
        turn = !turn;
    }
    is_winning();
}

void gameScreen::on_btn9_clicked()
{
    if(game_area[9-1] < 5)
    {
        if(turn)
        {
            ui->btn9->setText("X");
            game_area[9-1] = 10;
        }
        else
        {
            ui->btn9->setText("O");
            game_area[9-1] = 30;
        }
        turn = !turn;
    }
    is_winning();
}





