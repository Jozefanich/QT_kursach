#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QhBoxLayout>
#include <QList>
#include <QLabel>
#include <QString>
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    int m = 10;
    int n = 10;
    int size = 50;
    QList<QList<QLabel*>> list;
    QVBoxLayout *vbl = nullptr;
    // QHBoxLayout *hbl = nullptr;
    QWidget *main = nullptr;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void start_game();
    void load_field();
};
#endif // MAINWINDOW_H
