#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QVBoxLayout>
#include <QhBoxLayout>
#include <QList>
#include <QLabel>
#include <QString>
#include <QKeyEvent>
#include <QTimer>

class player : public QObject
{
    Q_OBJECT
public:
    player();
    void press_left();
    void press_right();
    void get_field_size(QPoint);
    void set_position(int, int);
    void moove(/*int, int*/);
    QPoint get_head_position();
    QList<QPoint> get_all_position(); //
    QPoint get_tail_position();
private:
    QList<QPoint> position;
    QPoint gate;
    QPoint way;
signals:
    void stop();
};

#endif // PLAYER_H
