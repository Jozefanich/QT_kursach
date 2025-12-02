#include "player.h"

player::player() {
    position.push_back({0,0});
    gate = {5,5};
}

void player::get_field_size(QPoint pt){
    // set field size
    gate = {pt.x()-1, pt.y()-1};
}

void player::set_position(int x, int y){
    //set snake position for the first time
    position[position.length()-1] = {x, y};
}

void player::moove(int x, int y){
    // qDebug() << x << " " << y;
    QPoint ps = QPoint(position[position.length()-1]);
    ps = {ps.x() + x, ps.y() + y};
    if(ps.x() < 0 or ps.x() > gate.x()or ps.y()< 0 or ps.y() > gate.y()){
        qDebug()<<"die";
    }
    else{
        qDebug() << x << " " << y;
        position[position.length()-1] = {ps.x(), ps.y()};
        qDebug() << position[position.length()-1];
    }
}
QPoint player::get_head_position(){
    return position.at(position.length()-1);
}
QPoint player::get_tail_position(){
    return position.at(0);
}
