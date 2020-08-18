#ifndef AIGAMESCREEN_H
#define AIGAMESCREEN_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class aiGameScreen;
}

class aiGameScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit aiGameScreen(QWidget *parent = nullptr);
    ~aiGameScreen();

private slots:
    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

    void on_btn6_clicked();

    void on_btn7_clicked();

    void on_btn8_clicked();

    void on_btn9_clicked();

private:
    Ui::aiGameScreen *ui;
    enum spot{
        CROSS = 2,
        CIRCLE = 1,
        NONE = 0
    };
    spot game_area[3][3] = {{NONE, NONE, NONE}, {NONE, NONE, NONE}, {NONE, NONE, NONE}};
    bool turn = true; // FALSE = AI TURN // TRUE = PLAYER MOVE
    bool setSpot(int number);
    void isWinning();
    void aiTurn();
    bool aiWinningMove();
    bool aiNotLoosingMove();
    bool aiPassiveMove();
};

#endif // AIGAMESCREEN_H
