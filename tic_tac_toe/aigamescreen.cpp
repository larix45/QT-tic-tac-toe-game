#include "aigamescreen.h"
#include "ui_aigamescreen.h"

aiGameScreen::aiGameScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::aiGameScreen)
{
    ui->setupUi(this);
}

aiGameScreen::~aiGameScreen()
{
    delete ui;
}

/*
 * [1,1 (1)]       [1,2 (2)]         [1,3 (3)]
 * [2,1 (4)]       [2,2 (5)]         [2,3 (6)]
 * [3,1 (7)]       [3,2 (8)]         [3,3 (9)]
 *
 * game_area
 */
const int OFFSET = -1;


bool aiGameScreen::aiWinningMove()
{
    //FIRST ROW
    if(game_area[1+OFFSET][1+OFFSET] == spot::NONE && game_area[1+OFFSET][2+OFFSET] == spot::CROSS && game_area[1+OFFSET][3+OFFSET] == spot::CROSS)
    {
        setSpot(1);
        return true;
    }
    else if(game_area[1+OFFSET][1+OFFSET] == spot::CROSS && game_area[1+OFFSET][2+OFFSET] == spot::NONE && game_area[1+OFFSET][3+OFFSET] == spot::CROSS)
    {
        setSpot(2);
        return true;
    }
    else if(game_area[1+OFFSET][1+OFFSET] == spot::CROSS && game_area[1+OFFSET][2+OFFSET] == spot::CROSS && game_area[1+OFFSET][3+OFFSET] == spot::NONE)
    {
        setSpot(3);
        return true;
    }

    //SECOND ROW
    else if(game_area[2+OFFSET][1+OFFSET] == spot::NONE && game_area[2+OFFSET][2+OFFSET] == spot::CROSS && game_area[2+OFFSET][3+OFFSET] == spot::CROSS)
    {
        setSpot(4);
        return true;
    }
    else if(game_area[2+OFFSET][1+OFFSET] == spot::CROSS && game_area[2+OFFSET][2+OFFSET] == spot::NONE && game_area[2+OFFSET][3+OFFSET] == spot::CROSS)
    {
        setSpot(5);
        return true;
    }
    else if(game_area[2+OFFSET][1+OFFSET] == spot::CROSS && game_area[2+OFFSET][2+OFFSET] == spot::CROSS && game_area[2+OFFSET][3+OFFSET] == spot::NONE)
    {
        setSpot(6);
        return true;
    }

    //THIRD ROW
    else if(game_area[3+OFFSET][1+OFFSET] == spot::NONE && game_area[3+OFFSET][2+OFFSET] == spot::CROSS && game_area[3+OFFSET][3+OFFSET] == spot::CROSS)
    {
        setSpot(7);
        return true;
    }
    else if(game_area[3+OFFSET][1+OFFSET] == spot::CROSS && game_area[3+OFFSET][2+OFFSET] == spot::NONE && game_area[3+OFFSET][3+OFFSET] == spot::CROSS)
    {
        setSpot(8);
        return true;
    }
    else if(game_area[3+OFFSET][1+OFFSET] == spot::CROSS && game_area[3+OFFSET][2+OFFSET] == spot::CROSS && game_area[3+OFFSET][3+OFFSET] == spot::NONE)
    {
        setSpot(9);
        return true;
    }

    //FIRST COLUMN
    else if(game_area[1+OFFSET][1+OFFSET] == spot::NONE && game_area[2+OFFSET][1+OFFSET] == spot::CROSS && game_area[3+OFFSET][1+OFFSET] == spot::CROSS)
    {
        setSpot(1);
        return true;
    }
    else if(game_area[1+OFFSET][1+OFFSET] == spot::CROSS && game_area[2+OFFSET][1+OFFSET] == spot::NONE && game_area[3+OFFSET][1+OFFSET] == spot::CROSS)
    {
        setSpot(4);
        return true;
    }
    else if(game_area[1+OFFSET][1+OFFSET] == spot::CROSS && game_area[2+OFFSET][1+OFFSET] == spot::CROSS && game_area[3+OFFSET][1+OFFSET] == spot::NONE)
    {
        setSpot(7);
        return true;
    }

    //SECOND COLUMN
    else if(game_area[1+OFFSET][2+OFFSET] == spot::NONE && game_area[2+OFFSET][2+OFFSET] == spot::CROSS && game_area[3+OFFSET][2+OFFSET] == spot::CROSS)
    {
        setSpot(2);
        return true;
    }
    else if(game_area[1+OFFSET][2+OFFSET] == spot::CROSS && game_area[2+OFFSET][2+OFFSET] == spot::NONE && game_area[3+OFFSET][2+OFFSET] == spot::CROSS)
    {
        setSpot(5);
        return true;
    }
    else if(game_area[1+OFFSET][2+OFFSET] == spot::CROSS && game_area[2+OFFSET][2+OFFSET] == spot::CROSS && game_area[3+OFFSET][2+OFFSET] == spot::NONE)
    {
        setSpot(8);
        return true;
    }

    //THIRD COLUMN
    else if(game_area[1+OFFSET][3+OFFSET] == spot::NONE && game_area[2+OFFSET][3+OFFSET] == spot::CROSS && game_area[3+OFFSET][3+OFFSET] == spot::CROSS)
    {
        setSpot(3);
        return true;
    }
    else if(game_area[1+OFFSET][3+OFFSET] == spot::CROSS && game_area[2+OFFSET][3+OFFSET] == spot::NONE && game_area[3+OFFSET][3+OFFSET] == spot::CROSS)
    {
        setSpot(6);
        return true;
    }
    else if(game_area[1+OFFSET][3+OFFSET] == spot::CROSS && game_area[2+OFFSET][3+OFFSET] == spot::CROSS && game_area[3+OFFSET][3+OFFSET] == spot::NONE)
    {
        setSpot(9);
        return true;
    }

    //X CROSS - LEFT UP
    else if(game_area[1+OFFSET][1+OFFSET] == spot::NONE && game_area[2+OFFSET][2+OFFSET] == spot::CROSS && game_area[3+OFFSET][3+OFFSET] == spot::CROSS)
    {
        setSpot(1);
        return true;
    }
    else if(game_area[1+OFFSET][1+OFFSET] == spot::CROSS && game_area[2+OFFSET][2+OFFSET] == spot::NONE && game_area[3+OFFSET][3+OFFSET] == spot::CROSS)
    {
        setSpot(5);
        return true;
    }
    else if(game_area[1+OFFSET][1+OFFSET] == spot::CROSS && game_area[2+OFFSET][2+OFFSET] == spot::CROSS && game_area[3+OFFSET][3+OFFSET] == spot::NONE)
    {
        setSpot(9);
        return true;
    }

    //X CROSS - RIGHT UP
    else if(game_area[1+OFFSET][3+OFFSET] == spot::NONE && game_area[2+OFFSET][2+OFFSET] == spot::CROSS && game_area[3+OFFSET][1+OFFSET] == spot::CROSS)
    {
        setSpot(3);
        return true;
    }
    else if(game_area[1+OFFSET][3+OFFSET] == spot::CROSS && game_area[2+OFFSET][2+OFFSET] == spot::NONE && game_area[3+OFFSET][1+OFFSET] == spot::CROSS)
    {
        setSpot(5);
        return true;
    }
    else if(game_area[1+OFFSET][3+OFFSET] == spot::CROSS && game_area[2+OFFSET][2+OFFSET] == spot::CROSS && game_area[3+OFFSET][1+OFFSET] == spot::NONE)
    {
        setSpot(7);
        return true;
    }
    return false;
}
bool aiGameScreen::aiNotLoosingMove()
{
    //FIRST ROW
    if(game_area[1+OFFSET][1+OFFSET] == spot::NONE && game_area[1+OFFSET][2+OFFSET] == spot::CIRCLE && game_area[1+OFFSET][3+OFFSET] == spot::CIRCLE)
    {
        setSpot(1);
        return true;
    }
    else if(game_area[1+OFFSET][1+OFFSET] == spot::CIRCLE && game_area[1+OFFSET][2+OFFSET] == spot::NONE && game_area[1+OFFSET][3+OFFSET] == spot::CIRCLE)
    {
        setSpot(2);
        return true;
    }
    else if(game_area[1+OFFSET][1+OFFSET] == spot::CIRCLE && game_area[1+OFFSET][2+OFFSET] == spot::CIRCLE && game_area[1+OFFSET][3+OFFSET] == spot::NONE)
    {
        setSpot(3);
        return true;
    }

    //SECOND ROW
    else if(game_area[2+OFFSET][1+OFFSET] == spot::NONE && game_area[2+OFFSET][2+OFFSET] == spot::CIRCLE && game_area[2+OFFSET][3+OFFSET] == spot::CIRCLE)
    {
        setSpot(4);
        return true;
    }
    else if(game_area[2+OFFSET][1+OFFSET] == spot::CIRCLE && game_area[2+OFFSET][2+OFFSET] == spot::NONE && game_area[2+OFFSET][3+OFFSET] == spot::CIRCLE)
    {
        setSpot(5);
        return true;
    }
    else if(game_area[2+OFFSET][1+OFFSET] == spot::CIRCLE && game_area[2+OFFSET][2+OFFSET] == spot::CIRCLE && game_area[2+OFFSET][3+OFFSET] == spot::NONE)
    {
        setSpot(6);
        return true;
    }

    //THIRD ROW
    else if(game_area[3+OFFSET][1+OFFSET] == spot::NONE && game_area[3+OFFSET][2+OFFSET] == spot::CIRCLE && game_area[3+OFFSET][3+OFFSET] == spot::CIRCLE)
    {
        setSpot(7);
        return true;
    }
    else if(game_area[3+OFFSET][1+OFFSET] == spot::CIRCLE && game_area[3+OFFSET][2+OFFSET] == spot::NONE && game_area[3+OFFSET][3+OFFSET] == spot::CIRCLE)
    {
        setSpot(8);
        return true;
    }
    else if(game_area[3+OFFSET][1+OFFSET] == spot::CIRCLE && game_area[3+OFFSET][2+OFFSET] == spot::CIRCLE && game_area[3+OFFSET][3+OFFSET] == spot::NONE)
    {
        setSpot(9);
        return true;
    }

    //FIRST COLUMN
    else if(game_area[1+OFFSET][1+OFFSET] == spot::NONE && game_area[2+OFFSET][1+OFFSET] == spot::CIRCLE && game_area[3+OFFSET][1+OFFSET] == spot::CIRCLE)
    {
        setSpot(1);
        return true;
    }
    else if(game_area[1+OFFSET][1+OFFSET] == spot::CIRCLE && game_area[2+OFFSET][1+OFFSET] == spot::NONE && game_area[3+OFFSET][1+OFFSET] == spot::CIRCLE)
    {
        setSpot(4);
        return true;
    }
    else if(game_area[1+OFFSET][1+OFFSET] == spot::CIRCLE && game_area[2+OFFSET][1+OFFSET] == spot::CIRCLE && game_area[3+OFFSET][1+OFFSET] == spot::NONE)
    {
        setSpot(7);
        return true;
    }

    //SECOND COLUMN
    else if(game_area[1+OFFSET][2+OFFSET] == spot::NONE && game_area[2+OFFSET][2+OFFSET] == spot::CIRCLE && game_area[3+OFFSET][2+OFFSET] == spot::CIRCLE)
    {
        setSpot(2);
        return true;
    }
    else if(game_area[1+OFFSET][2+OFFSET] == spot::CIRCLE && game_area[2+OFFSET][2+OFFSET] == spot::NONE && game_area[3+OFFSET][2+OFFSET] == spot::CIRCLE)
    {
        setSpot(5);
        return true;
    }
    else if(game_area[1+OFFSET][2+OFFSET] == spot::CIRCLE && game_area[2+OFFSET][2+OFFSET] == spot::CIRCLE && game_area[3+OFFSET][2+OFFSET] == spot::NONE)
    {
        setSpot(8);
        return true;
    }

    //THIRD COLUMN
    else if(game_area[1+OFFSET][3+OFFSET] == spot::NONE && game_area[2+OFFSET][3+OFFSET] == spot::CIRCLE && game_area[3+OFFSET][3+OFFSET] == spot::CIRCLE)
    {
        setSpot(3);
        return true;
    }
    else if(game_area[1+OFFSET][3+OFFSET] == spot::CIRCLE && game_area[2+OFFSET][3+OFFSET] == spot::NONE && game_area[3+OFFSET][3+OFFSET] == spot::CIRCLE)
    {
        setSpot(6);
        return true;
    }
    else if(game_area[1+OFFSET][3+OFFSET] == spot::CIRCLE && game_area[2+OFFSET][3+OFFSET] == spot::CIRCLE && game_area[3+OFFSET][3+OFFSET] == spot::NONE)
    {
        setSpot(9);
        return true;
    }

    //X CROSS - LEFT UP
    else if(game_area[1+OFFSET][1+OFFSET] == spot::NONE && game_area[2+OFFSET][2+OFFSET] == spot::CIRCLE && game_area[3+OFFSET][3+OFFSET] == spot::CIRCLE)
    {
        setSpot(1);
        return true;
    }
    else if(game_area[1+OFFSET][1+OFFSET] == spot::CIRCLE && game_area[2+OFFSET][2+OFFSET] == spot::NONE && game_area[3+OFFSET][3+OFFSET] == spot::CIRCLE)
    {
        setSpot(5);
        return true;
    }
    else if(game_area[1+OFFSET][1+OFFSET] == spot::CIRCLE && game_area[2+OFFSET][2+OFFSET] == spot::CIRCLE && game_area[3+OFFSET][3+OFFSET] == spot::NONE)
    {
        setSpot(9);
        return true;
    }

    //X CROSS - RIGHT UP
    else if(game_area[1+OFFSET][3+OFFSET] == spot::NONE && game_area[2+OFFSET][2+OFFSET] == spot::CIRCLE && game_area[3+OFFSET][1+OFFSET] == spot::CIRCLE)
    {
        setSpot(3);
        return true;
    }
    else if(game_area[1+OFFSET][3+OFFSET] == spot::CIRCLE && game_area[2+OFFSET][2+OFFSET] == spot::NONE && game_area[3+OFFSET][1+OFFSET] == spot::CIRCLE)
    {
        setSpot(5);
        return true;
    }
    else if(game_area[1+OFFSET][3+OFFSET] == spot::CIRCLE && game_area[2+OFFSET][2+OFFSET] == spot::CIRCLE && game_area[3+OFFSET][1+OFFSET] == spot::NONE)
    {
        setSpot(7);
        return true;
    }
    return false;
}
bool aiGameScreen::aiPassiveMove()
{
        if(setSpot(5))
            return true;
        else if(setSpot(4))
            return true;
        else if(setSpot(6))
            return true;
        else if(setSpot(8))
            return true;
        else if(setSpot(2))
            return true;
        else if(setSpot(9))
            return true;
        else if(setSpot(1))
            return true;
        else if(setSpot(3))
            return true;
        else if(setSpot(7))
            return true;
        else
            return false;
}
void aiGameScreen::isWinning()
{
    if((game_area[1+OFFSET][1+OFFSET] == spot::CROSS && game_area[1+OFFSET][2+OFFSET] == spot::CROSS && game_area[1+OFFSET][3+OFFSET] == spot::CROSS) ||
       (game_area[2+OFFSET][1+OFFSET] == spot::CROSS && game_area[2+OFFSET][2+OFFSET] == spot::CROSS && game_area[2+OFFSET][3+OFFSET] == spot::CROSS) ||
       (game_area[3+OFFSET][1+OFFSET] == spot::CROSS && game_area[3+OFFSET][2+OFFSET] == spot::CROSS && game_area[3+OFFSET][3+OFFSET] == spot::CROSS) ||

       (game_area[1+OFFSET][1+OFFSET] == spot::CROSS && game_area[2+OFFSET][1+OFFSET] == spot::CROSS && game_area[3+OFFSET][1+OFFSET] == spot::CROSS) ||
       (game_area[1+OFFSET][2+OFFSET] == spot::CROSS && game_area[2+OFFSET][2+OFFSET] == spot::CROSS && game_area[3+OFFSET][2+OFFSET] == spot::CROSS) ||
       (game_area[1+OFFSET][3+OFFSET] == spot::CROSS && game_area[2+OFFSET][3+OFFSET] == spot::CROSS && game_area[3+OFFSET][3+OFFSET] == spot::CROSS) ||

       (game_area[1+OFFSET][1+OFFSET] == spot::CROSS && game_area[2+OFFSET][2+OFFSET] == spot::CROSS && game_area[3+OFFSET][3+OFFSET] == spot::CROSS) ||
       (game_area[1+OFFSET][3+OFFSET] == spot::CROSS && game_area[2+OFFSET][2+OFFSET] == spot::CROSS && game_area[3+OFFSET][1+OFFSET] == spot::CROSS)
           )
    {

        QMessageBox msgBox;
        msgBox.setText("Wygrywa gracz krzyżyk");
        msgBox.exec();
        QApplication::exit();
    }
    else
        if((game_area[1+OFFSET][1+OFFSET] == spot::CIRCLE && game_area[1+OFFSET][2+OFFSET] == spot::CIRCLE && game_area[1+OFFSET][3+OFFSET] == spot::CIRCLE) ||
           (game_area[2+OFFSET][1+OFFSET] == spot::CIRCLE && game_area[2+OFFSET][2+OFFSET] == spot::CIRCLE && game_area[2+OFFSET][3+OFFSET] == spot::CIRCLE) ||
           (game_area[3+OFFSET][1+OFFSET] == spot::CIRCLE && game_area[3+OFFSET][2+OFFSET] == spot::CIRCLE && game_area[3+OFFSET][3+OFFSET] == spot::CIRCLE) ||

           (game_area[1+OFFSET][1+OFFSET] == spot::CIRCLE && game_area[2+OFFSET][1+OFFSET] == spot::CIRCLE && game_area[3+OFFSET][1+OFFSET] == spot::CIRCLE) ||
           (game_area[1+OFFSET][2+OFFSET] == spot::CIRCLE && game_area[2+OFFSET][2+OFFSET] == spot::CIRCLE && game_area[3+OFFSET][2+OFFSET] == spot::CIRCLE) ||
           (game_area[1+OFFSET][3+OFFSET] == spot::CIRCLE && game_area[2+OFFSET][3+OFFSET] == spot::CIRCLE && game_area[3+OFFSET][3+OFFSET] == spot::CIRCLE) ||

           (game_area[1+OFFSET][1+OFFSET] == spot::CIRCLE && game_area[2+OFFSET][2+OFFSET] == spot::CIRCLE && game_area[3+OFFSET][3+OFFSET] == spot::CIRCLE) ||
           (game_area[1+OFFSET][3+OFFSET] == spot::CIRCLE && game_area[2+OFFSET][2+OFFSET] == spot::CIRCLE && game_area[3+OFFSET][1+OFFSET] == spot::CIRCLE)
            )
        {

             QMessageBox msgBox;
             msgBox.setText("Wygrywa gracz kolko");
             msgBox.exec();
             QApplication::exit();
        }
    if(game_area[1+OFFSET][1+OFFSET] != spot::NONE &&
       game_area[1+OFFSET][2+OFFSET] != spot::NONE &&
       game_area[1+OFFSET][3+OFFSET] != spot::NONE &&
       game_area[2+OFFSET][1+OFFSET] != spot::NONE &&
       game_area[2+OFFSET][2+OFFSET] != spot::NONE &&
       game_area[2+OFFSET][3+OFFSET] != spot::NONE &&
       game_area[3+OFFSET][1+OFFSET] != spot::NONE &&
       game_area[3+OFFSET][2+OFFSET] != spot::NONE &&
       game_area[3+OFFSET][3+OFFSET] != spot::NONE )
    {
        QMessageBox msgBox;
        msgBox.setText("Remis");
        msgBox.exec();
        exit(0);
        QApplication::exit();
    }
}
bool aiGameScreen::setSpot(int number)
{
    if(game_area[(number-1)/ 3][(number-1) % 3] == 0)
    {
        if(turn)
            switch (number)
            {
            case 1:
                ui->btn1->setText("X");
                ui->btn1->setEnabled(false);
                game_area[1+OFFSET][1+OFFSET] = spot::CROSS;
                break;
            case 2:
                ui->btn2->setText("X");
                ui->btn2->setEnabled(false);
                game_area[1+OFFSET][2+OFFSET] = spot::CROSS;
                break;
            case 3:
                ui->btn3->setText("X");
                ui->btn3->setEnabled(false);
                game_area[1+OFFSET][3+OFFSET] = spot::CROSS;
                break;
            case 4:
                ui->btn4->setText("X");
                ui->btn4->setEnabled(false);
                game_area[2+OFFSET][1+OFFSET] = spot::CROSS;
                break;
            case 5:
                ui->btn5->setText("X");
                ui->btn5->setEnabled(false);
                game_area[2+OFFSET][2+OFFSET] = spot::CROSS;
                break;
            case 6:
                ui->btn6->setText("X");
                ui->btn6->setEnabled(false);
                game_area[2+OFFSET][3+OFFSET] = spot::CROSS;
                break;
            case 7:
                ui->btn7->setText("X");
                ui->btn7->setEnabled(false);
                game_area[3+OFFSET][1+OFFSET] = spot::CROSS;
                break;
            case 8:
                ui->btn8->setText("X");
                ui->btn8->setEnabled(false);
                game_area[3+OFFSET][2+OFFSET] = spot::CROSS;
                break;
            case 9:
                ui->btn9->setText("X");
                ui->btn9->setEnabled(false);
                game_area[3+OFFSET][3+OFFSET] = spot::CROSS;
                break;
            }
        else
            switch (number)
            {
            case 1:
                ui->btn1->setText("O");
                ui->btn1->setEnabled(false);
                game_area[1+OFFSET][1+OFFSET] = spot::CIRCLE;
                break;
            case 2:
                ui->btn2->setText("O");
                ui->btn2->setEnabled(false);
                game_area[1+OFFSET][2+OFFSET] = spot::CIRCLE;
                break;
            case 3:
                ui->btn3->setText("O");
                ui->btn3->setEnabled(false);
                game_area[1+OFFSET][3+OFFSET] = spot::CIRCLE;
                break;
            case 4:
                ui->btn4->setText("O");
                ui->btn4->setEnabled(false);
                game_area[2+OFFSET][1+OFFSET] = spot::CIRCLE;
                break;
            case 5:
                ui->btn5->setText("O");
                ui->btn5->setEnabled(false);
                game_area[2+OFFSET][2+OFFSET] = spot::CIRCLE;
                break;
            case 6:
                ui->btn6->setText("O");
                ui->btn6->setEnabled(false);
                game_area[2+OFFSET][3+OFFSET] = spot::CIRCLE;
                break;
            case 7:
                ui->btn7->setText("O");
                ui->btn7->setEnabled(false);
                game_area[3+OFFSET][1+OFFSET] = spot::CIRCLE;
                break;
            case 8:
                ui->btn8->setText("O");
                ui->btn8->setEnabled(false);
                game_area[3+OFFSET][2+OFFSET] = spot::CIRCLE;
                break;
            case 9:
                ui->btn9->setText("O");
                ui->btn9->setEnabled(false);
                game_area[3+OFFSET][3+OFFSET] = spot::CIRCLE;
                break;
            }
        turn = !turn;
        isWinning();
        return true;
    }
    return false;

}
void aiGameScreen::aiTurn()
{
    if(aiWinningMove())
        return;
    else if (aiNotLoosingMove())
        return;
    else while(!aiPassiveMove())
    {}
}
void aiGameScreen::on_btn1_clicked()
{
    if(setSpot(1))
        aiTurn();
}

void aiGameScreen::on_btn2_clicked()
{
    if(setSpot(2))
         aiTurn();
}

void aiGameScreen::on_btn3_clicked()
{
    if(setSpot(3))
        aiTurn();
}

void aiGameScreen::on_btn4_clicked()
{
    if(setSpot(4))
        aiTurn();
}

void aiGameScreen::on_btn5_clicked()
{
    if(setSpot(5))
        aiTurn();
}

void aiGameScreen::on_btn6_clicked()
{
    if(setSpot(6))
        aiTurn();
}

void aiGameScreen::on_btn7_clicked()
{
    if(setSpot(7))
        aiTurn();
}

void aiGameScreen::on_btn8_clicked()
{
    if(setSpot(8))
        aiTurn();
}

void aiGameScreen::on_btn9_clicked()
{
    if(setSpot(9))
        aiTurn();
}
