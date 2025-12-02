#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){
    snake = new player();
    load_field();
    start_game();
    snake->set_position(0,0);
    snake->get_field_size({m,n});
    set_color({0,0}, true);
    qDebug() << snake->get_head_position();
    // main->setFocus();
}

void MainWindow::load_field(){
    vbl = new QVBoxLayout(this);
    for(int i=0; i<m; i++){
        QList<QLabel*> RowItem;
        QHBoxLayout *hbl = new QHBoxLayout();
        for(int i=0; i<n; i++){
            QLabel *cl = new QLabel();
            cl->setFixedSize(20,20);
            QString color = "background-color:";
            color += (((m+n)%2)==0?"green;":"lime;");
            cl->setStyleSheet(color);
            RowItem.append(cl);
            hbl->addWidget(cl);
        }
        list.prepend(RowItem);
        vbl->addLayout(hbl);
    }
}
void MainWindow::set_color(QPoint pt, bool next = false){
    QString style = "background-color:";
    style+= (next)?"red;":"green";
    list[pt.y()][pt.x()]->setStyleSheet(style);
}
void MainWindow::start_game(){
    main = new QWidget(this);
    setCentralWidget(main);
    main->setLayout(vbl);
    main->show();
    // qDebug() << list[0][0]->styleSheet();
}
void MainWindow::keyPressEvent(QKeyEvent *event){
    int key = event->key();
    QPoint pt = snake->get_head_position();
    if(key == Qt::Key_Up){
        set_color(pt);
        snake->moove(0,1);
        set_color(snake->get_head_position(), true);
    }
    else if(key == Qt::Key_Down){
        set_color(pt);
        snake->moove(0,-1);
        set_color(snake->get_head_position() , true);
    }
    else if(key == Qt::Key_Left){
        set_color(pt);
        snake->moove(-1,0);
        set_color(snake->get_head_position(), true);
    }
    else if(key == Qt::Key_Right){
        set_color(pt);
        snake->moove(1,0);
        set_color(snake->get_head_position() , true);
    }
}
void update_head_position(int x, int y){

}
MainWindow::~MainWindow(){}
