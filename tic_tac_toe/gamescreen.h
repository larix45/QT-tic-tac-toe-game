#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class gameScreen;
}

class gameScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit gameScreen(QWidget *parent = nullptr);
    ~gameScreen();
private slots:
    void on_btn8_clicked();

    void on_btn9_clicked();

    void on_btn7_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

    void on_btn6_clicked();

    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

private:
    Ui::gameScreen *ui;
    char game_area[9] = {0,0,0,0,0,0,0,0,0};
    bool turn = true;
    void is_winning();

};

#endif // GAMESCREEN_H
