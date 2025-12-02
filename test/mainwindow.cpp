#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){
    load_field();
    start_game();
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
        list.push_back(RowItem);
        vbl->addLayout(hbl);
    }
}
void MainWindow::start_game(){
    main = new QWidget(this);
    setCentralWidget(main);
    main->setLayout(vbl);
    main->show();
    list[0][0]->setStyleSheet("background-color: red;");
    qDebug() << list[0][0]->styleSheet();
}
MainWindow::~MainWindow(){}
