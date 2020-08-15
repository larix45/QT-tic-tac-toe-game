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
    ai_stage();
    if((game_area[1-1] == 10 && game_area[2-1] == 10 && game_area[3-1] == 10) ||
       (game_area[4-1] == 10 && game_area[5-1] == 10 && game_area[6-1] == 10) ||
       (game_area[7-1] == 10 && game_area[8-1] == 10 && game_area[9-1] == 10) ||
       (game_area[1-1] == 10 && game_area[4-1] == 10 && game_area[7-1] == 10) ||
       (game_area[2-1] == 10 && game_area[5-1] == 10 && game_area[8-1] == 10) ||
       (game_area[3-1] == 10 && game_area[6-1] == 10 && game_area[9-1] == 10) ||
       (game_area[1-1] == 10 && game_area[5-1] == 10 && game_area[9-1] == 10) ||
       (game_area[3-1] == 10 && game_area[5-1] == 10 && game_area[7-1] == 10)
           )
    {

        QMessageBox msgBox;
        msgBox.setText("Wygrywa gracz krzyżyk");
        msgBox.exec();
        QApplication::exit();
    }
    else if((game_area[1-1] == 30 && game_area[2-1] == 30 && game_area[3-1] == 30) ||
            (game_area[4-1] == 30 && game_area[5-1] == 30 && game_area[6-1] == 30) ||
            (game_area[7-1] == 30 && game_area[8-1] == 30 && game_area[9-1] == 30) ||
            (game_area[1-1] == 30 && game_area[4-1] == 30 && game_area[7-1] == 30) ||
            (game_area[2-1] == 30 && game_area[5-1] == 30 && game_area[8-1] == 30) ||
            (game_area[3-1] == 30 && game_area[6-1] == 30 && game_area[9-1] == 30) ||
            (game_area[1-1] == 30 && game_area[5-1] == 30 && game_area[9-1] == 30) ||
            (game_area[3-1] == 30 && game_area[5-1] == 30 && game_area[7-1] == 30)
               )
    {

         QMessageBox msgBox;
         msgBox.setText("Wygrywa gracz kolko");
         msgBox.exec();
         QApplication::exit();
    }
    if(game_area[1-1] < 5 &&
       game_area[2-1] < 5 &&
       game_area[3-1] < 5 &&
       game_area[4-1] < 5 &&
       game_area[5-1] < 5 &&
       game_area[6-1] < 5 &&
       game_area[7-1] < 5 &&
       game_area[8-1] < 5 &&
       game_area[9-1] < 5 )
    {
        QMessageBox msgBox;
        msgBox.setText("Remis");
        msgBox.exec();
        QApplication::exit();
    }
}
void gameScreen::ai_stage()
{
    if(game == 1)
    {
        //IF I CAN WIN  []
        //IF I CAN LOSE [x]
        //PASSIVE       [x]



        if(game_area[5-1] == 0)
        {
            game_area[5-1] = 30;
            ui->btn5->setText("O");
        }
        else
        {
            //IF I CAN WIN
                //FIRST ROW
            if(game_area[1-1] == 30 && game_area[2-1] == 30 && game_area[3-1] == 0)
            {
                game_area[3-1] = 30;
                ui->btn3->setText("O");
            }
            else if(game_area[1-1] == 30 && game_area[2-1] == 0 && game_area[3-1] == 30)
            {
                game_area[2-1] = 30;
                ui->btn2->setText("O");
            }
            else if(game_area[1-1] == 0 && game_area[2-1] == 30 && game_area[3-1] == 30)
            {
                game_area[1-1] = 30;
                ui->btn1->setText("O");
            }
                //SECOND ROW
            else if(game_area[4-1] == 30 && game_area[5-1] == 30 && game_area[6-1] == 0)
            {
                game_area[6-1] = 30;
                ui->btn6->setText("O");
            }
            else if(game_area[4-1] == 30 && game_area[5-1] == 0 && game_area[6-1] == 30)
            {
                game_area[5-1] = 30;
                ui->btn5->setText("O");
            }
            else if(game_area[4-1] == 0 && game_area[5-1] == 30 && game_area[6-1] == 30)
            {
                game_area[4-1] = 30;
                ui->btn4->setText("O");
            }
                //THIRD ROW
            else if(game_area[7-1] == 30 && game_area[8-1] == 30 && game_area[9-1] == 0)
            {
                game_area[9-1] = 30;
                ui->btn9->setText("O");
            }
            else if(game_area[7-1] == 30 && game_area[8-1] == 0 && game_area[9-1] == 30)
            {
                game_area[8-1] = 30;
                ui->btn8->setText("O");
            }
            else if(game_area[7-1] == 0 && game_area[8-1] == 30 && game_area[9-1] == 30)
            {
                game_area[7-1] = 30;
                ui->btn7->setText("O");
            }
                //FIRST COLUMN
            else if(game_area[1-1] == 30 && game_area[4-1] == 30 && game_area[7-1] == 0)
            {
                game_area[7-1] = 30;
                ui->btn7->setText("O");
            }
            else if(game_area[1-1] == 30 && game_area[4-1] == 0 && game_area[7-1] == 30)
            {
                game_area[4-1] = 30;
                ui->btn4->setText("O");
            }
            else if(game_area[1-1] == 0 && game_area[4-1] == 30 && game_area[7-1] == 30)
            {
                game_area[1-1] = 30;
                ui->btn1->setText("O");
            }
                //SECOND COLUMN
            else if(game_area[2-1] == 30 && game_area[5-1] == 30 && game_area[8-1] == 0)
            {
                game_area[8-1] = 30;
                ui->btn8->setText("O");
            }
            else if(game_area[2-1] == 30 && game_area[5-1] == 0 && game_area[8-1] == 30)
            {
                game_area[5-1] = 30;
                ui->btn5->setText("O");
            }
            else if(game_area[2-1] == 0 && game_area[5-1] == 30 && game_area[8-1] == 30)
            {
                game_area[2-1] = 30;
                ui->btn2->setText("O");
            }
                //THIRD COLUMN
            else if(game_area[3-1] == 30 && game_area[6-1] == 30 && game_area[9-1] == 0)
            {
                game_area[9-1] = 30;
                ui->btn9->setText("O");
            }
            else if(game_area[3-1] == 30 && game_area[6-1] == 0 && game_area[9-1] == 30)
            {
                game_area[6-1] = 30;
                ui->btn6->setText("O");
            }
            else if(game_area[3-1] == 0 && game_area[6-1] == 30 && game_area[9-1] == 30)
            {
                game_area[3-1] = 30;
                ui->btn3->setText("O");
            }
                //X CROSS
            else if(game_area[1-1] == 30 && game_area[5-1] == 30 && game_area[9-1] == 0)
            {
                game_area[9-1] = 30;
                ui->btn9->setText("O");
            }
            else if(game_area[1-1] == 30 && game_area[5-1] == 0 && game_area[9-1] == 30)
            {
                game_area[5-1] = 30;
                ui->btn5->setText("O");
            }
            else if(game_area[1-1] == 0 && game_area[5-1] == 30 && game_area[9-1] == 30)
            {
                game_area[1-1] = 30;
                ui->btn1->setText("O");
            }
            else if(game_area[3-1] == 30 && game_area[5-1] == 30 && game_area[7-1] == 0)
            {
                game_area[7-1] = 30;
                ui->btn7->setText("O");
            }
            else if(game_area[3-1] == 30 && game_area[5-1] == 0 && game_area[7-1] == 30)
            {
                game_area[5-1] = 30;
                ui->btn5->setText("O");
            }
            else if(game_area[3-1] == 0 && game_area[5-1] == 30 && game_area[7-1] == 30)
            {
                game_area[3-1] = 30;
                ui->btn3->setText("O");
            }



            //IF I CAN LOSE
            if(game_area[1-1] == 10 && game_area[2-1] == 10 && game_area[3-1] == 0)
            {
                game_area[3-1] = 30;
                ui->btn3->setText("O");
            }
            else if(game_area[1-1] == 10 && game_area[2-1] == 0 && game_area[3-1] == 10)
            {
                game_area[2-1] = 30;
                ui->btn2->setText("O");
            }
            else if(game_area[1-1] == 0 && game_area[2-1] == 10 && game_area[3-1] == 10)
            {
                game_area[1-1] = 30;
                ui->btn1->setText("O");
            }
                //SECOND ROW
            else if(game_area[4-1] == 10 && game_area[5-1] == 10 && game_area[6-1] == 0)
            {
                game_area[6-1] = 30;
                ui->btn6->setText("O");
            }
            else if(game_area[4-1] == 10 && game_area[5-1] == 0 && game_area[6-1] == 10)
            {
                game_area[5-1] = 30;
                ui->btn5->setText("O");
            }
            else if(game_area[4-1] == 0 && game_area[5-1] == 10 && game_area[6-1] == 10)
            {
                game_area[4-1] = 30;
                ui->btn4->setText("O");
            }
                //THIRD ROW
            else if(game_area[7-1] == 10 && game_area[8-1] == 10 && game_area[9-1] == 0)
            {
                game_area[9-1] = 30;
                ui->btn9->setText("O");
            }
            else if(game_area[7-1] == 10 && game_area[8-1] == 0 && game_area[9-1] == 10)
            {
                game_area[8-1] = 30;
                ui->btn8->setText("O");
            }
            else if(game_area[7-1] == 0 && game_area[8-1] == 10 && game_area[9-1] == 10)
            {
                game_area[7-1] = 30;
                ui->btn7->setText("O");
            }
                //FIRST COLUMN
            else if(game_area[1-1] == 10 && game_area[4-1] == 10 && game_area[7-1] == 0)
            {
                game_area[7-1] = 30;
                ui->btn7->setText("O");
            }
            else if(game_area[1-1] == 10 && game_area[4-1] == 0 && game_area[7-1] == 10)
            {
                game_area[4-1] = 30;
                ui->btn4->setText("O");
            }
            else if(game_area[1-1] == 0 && game_area[4-1] == 10 && game_area[7-1] == 10)
            {
                game_area[1-1] = 30;
                ui->btn1->setText("O");
            }
                //SECOND COLUMN
            else if(game_area[2-1] == 10 && game_area[5-1] == 10 && game_area[8-1] == 0)
            {
                game_area[8-1] = 30;
                ui->btn8->setText("O");
            }
            else if(game_area[2-1] == 10 && game_area[5-1] == 0 && game_area[8-1] == 10)
            {
                game_area[5-1] = 30;
                ui->btn5->setText("O");
            }
            else if(game_area[2-1] == 0 && game_area[5-1] == 10 && game_area[8-1] == 10)
            {
                game_area[2-1] = 30;
                ui->btn2->setText("O");
            }
                //THIRD COLUMN
            else if(game_area[3-1] == 10 && game_area[6-1] == 10 && game_area[9-1] == 0)
            {
                game_area[9-1] = 30;
                ui->btn9->setText("O");
            }
            else if(game_area[3-1] == 10 && game_area[6-1] == 0 && game_area[9-1] == 10)
            {
                game_area[6-1] = 30;
                ui->btn6->setText("O");
            }
            else if(game_area[3-1] == 0 && game_area[6-1] == 10 && game_area[9-1] == 10)
            {
                game_area[3-1] = 30;
                ui->btn3->setText("O");
            }
                //X CROSS
            else if(game_area[1-1] == 10 && game_area[5-1] == 10 && game_area[9-1] == 0)
            {
                game_area[9-1] = 30;
                ui->btn9->setText("O");
            }
            else if(game_area[1-1] == 10 && game_area[5-1] == 0 && game_area[9-1] == 10)
            {
                game_area[5-1] = 30;
                ui->btn5->setText("O");
            }
            else if(game_area[1-1] == 0 && game_area[5-1] == 10 && game_area[9-1] == 10)
            {
                game_area[1-1] = 30;
                ui->btn1->setText("O");
            }
            else if(game_area[3-1] == 10 && game_area[5-1] == 10 && game_area[7-1] == 0)
            {
                game_area[7-1] = 30;
                ui->btn7->setText("O");
            }
            else if(game_area[3-1] == 10 && game_area[5-1] == 0 && game_area[7-1] == 10)
            {
                game_area[5-1] = 30;
                ui->btn5->setText("O");
            }
            else if(game_area[3-1] == 0 && game_area[5-1] == 10 && game_area[7-1] == 10)
            {
                game_area[3-1] = 30;
                ui->btn3->setText("O");
            }






            if(game_area[5-1] == 10)
            {
                if(game_area[1-1] == 10 && game_area[9-1] == 0)
                {
                    game_area[9-1] = 30;
                    ui->btn9->setText("O");
                }
                else if(game_area[3-1] == 10 && game_area[7-1] == 0)
                {
                    game_area[7-1] = 30;
                    ui->btn7->setText("O");
                }
                else if(game_area[7-1] == 10 && game_area[3-1] == 0)
                {
                    game_area[3-1] = 30;
                    ui->btn3->setText("O");
                }
                else if(game_area[9-1] == 10 && game_area[1-1] == 0)
                {
                    game_area[1-1] = 30;
                    ui->btn1->setText("O");
                }
                else if(game_area[2-1] == 10 && game_area[8-1] == 0)
                {
                    game_area[8-1] = 30;
                    ui->btn8->setText("O");
                }
                else if(game_area[8-1] == 10 && game_area[2-1] == 0)
                {
                    game_area[2-1] = 30;
                    ui->btn2->setText("O");
                }
                else if(game_area[4-1] == 10 && game_area[6-1] == 0)
                {
                    game_area[6-1] = 30;
                    ui->btn6->setText("O");
                }
                else if(game_area[6-1] == 10 && game_area[4-1] == 0)
                {
                    game_area[4-1] = 30;
                    ui->btn4->setText("O");
                }
            }
            else//PASSIVE MOVES
            {
                if(game_area[1-1] == 0)
                {
                    game_area[1-1] = 30;
                    ui->btn1->setText("O");
                }
                else if(game_area[2-1] == 0)
                {
                    game_area[2-1] = 30;
                    ui->btn2->setText("O");
                }
                else if(game_area[3-1] == 0)
                {
                    game_area[3-1] = 30;
                    ui->btn3->setText("O");
                }
                else if(game_area[4-1] == 0)
                {
                    game_area[4-1] = 30;
                    ui->btn4->setText("O");
                }
                else if(game_area[6-1] == 0)
                {
                    game_area[6-1] = 30;
                    ui->btn6->setText("O");
                }
                else if(game_area[7-1] == 0)
                {
                    game_area[7-1] = 30;
                    ui->btn7->setText("O");
                }
                else if(game_area[8-1] == 0)
                {
                    game_area[8-1] = 30;
                    ui->btn8->setText("O");
                }
                else if(game_area[9-1] == 0)
                {
                    game_area[9-1] = 30;
                    ui->btn9->setText("O");
                }
            }
            /*
             * [1][2][3]
             * [4][5][6]
             * [7][8][9]
             */
        }




        turn = !turn;
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





