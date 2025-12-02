#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "player.h"
#include <QMainWindow>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    int m = 10;
    int n = 10;
    int size = 50;
    QList<QList<QLabel*>> list;
    QVBoxLayout *vbl = nullptr;
    player *snake;
    // QHBoxLayout *hbl = nullptr;
    QWidget *main = nullptr;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void start_game();
    void load_field();
    // void update_head_position(int, int);
    void set_color(QPoint, bool);
protected:
    void keyPressEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H
