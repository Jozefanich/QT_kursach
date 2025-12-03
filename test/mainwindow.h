#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "player.h"
#include <QMainWindow>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    int m = 10; // x
    int n = 10; // y
    int size = 50; // cell size
    QList<QList<QLabel*>> list; // matrix of label pointers
    QVBoxLayout *vbl = nullptr;
    player *snake;
    QTimer *timer = nullptr; // auto moove
    int base_key = 16777234;
    int index = 3;
    QWidget *main = nullptr;
private slots:
    void player_moove();// start game, snake moove forvard untill die
public slots:
    void stop_timer();// when player die
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void start_game();
    void load_field();
    void set_color(QPoint, bool);
protected:
    void keyPressEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H
