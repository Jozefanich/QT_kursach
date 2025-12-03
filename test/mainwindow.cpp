#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){
    snake = new player(); // player class
    connect(snake, &player::stop, this, &MainWindow::stop_timer);
    load_field(); // create field matrix
    start_game(); // load matrix to main widget
    snake->set_position((m+1)/2,(n+1)/2); // set base player position
    snake->get_field_size({m,n}); // set value into local variable
    set_color(snake->get_head_position(), true); // change color on cell with player for the first time
    qDebug() << snake->get_head_position();
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, MainWindow::player_moove); // move snake forward untill die
}

void MainWindow::load_field(){
    vbl = new QVBoxLayout(this);
    for(int i=0; i<m; i++){
        QList<QLabel*> RowItem;
        QHBoxLayout *hbl = new QHBoxLayout();
        for(int i=0; i<n; i++){
            // creating Label`s, set styleSheet on it and push into HBoxLayout
            QLabel *cl = new QLabel();
            cl->setFixedSize(20,20); // set size for cell
            QString color = "background-color:";
            color += (((m+n)%2)==0?"green;":"lime;");
            cl->setStyleSheet(color);
            RowItem.append(cl); // save pointer to label for changing stile
            hbl->addWidget(cl); // push label into HBoxLayout
        }
        list.prepend(RowItem); // insert list with pointers to first position on pointer matrix
        vbl->addLayout(hbl);
    }
}
void MainWindow::set_color(QPoint pt, bool next = false){
    QString style = "background-color:";
    style+= (next)?"red;":"green"; // player = red, empty field = green
    list[pt.y()][pt.x()]->setStyleSheet(style); // set style to label
}
void MainWindow::start_game(){
    main = new QWidget(this);
    setCentralWidget(main);
    main->setLayout(vbl);
    main->show();
    // qDebug() << list[0][0]->styleSheet();
}
void MainWindow::player_moove(){
    set_color(snake->get_tail_position()); // clear position where were snake tail
    snake->moove(); // moove
    set_color(snake->get_head_position(), true); // change color were snake head now
}

void MainWindow::stop_timer()
{
    qDebug() << "got it";
    timer->stop();
}
void MainWindow::keyPressEvent(QKeyEvent *event){
    int key = event->key();
    if(key == Qt::Key_1){
        if(!timer->isActive()){
            timer->start(500);
        }
    }
    qDebug() << "key:   " <<key;
    qDebug() << "base:  " <<base_key; // basa - Key_Right number
    qDebug() << "index: " <<index; // index used for calculate values from Key_Right to Key_Down
    if(key == (base_key+(index==0?3:index-1))){
        index = index==0?3:index-1;
        snake->press_left();
        }
    else if(key == base_key+(index+1)%4){
        index = (index+1)%4;
        snake->press_right();
    }
}
MainWindow::~MainWindow(){}
