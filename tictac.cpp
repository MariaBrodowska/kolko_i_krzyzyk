
#include "tictac.h"
#include "ui_tictac.h"


tictac::tictac(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::tictac)
{
    ui->setupUi(this);
    kto = kolko;
    for(int i=0;i<9;i++){
        pole[i]="";
    }
    QObject::connect(ui->P1,SIGNAL(clicked()),this,SLOT(buttonClicked1()));
    QObject::connect(ui->P2,SIGNAL(clicked()),this,SLOT(buttonClicked2()));
    QObject::connect(ui->P3,SIGNAL(clicked()),this,SLOT(buttonClicked3()));
    QObject::connect(ui->P4,SIGNAL(clicked()),this,SLOT(buttonClicked4()));
    QObject::connect(ui->P5,SIGNAL(clicked()),this,SLOT(buttonClicked5()));
    QObject::connect(ui->P6,SIGNAL(clicked()),this,SLOT(buttonClicked6()));
    QObject::connect(ui->P7,SIGNAL(clicked()),this,SLOT(buttonClicked7()));
    QObject::connect(ui->P8,SIGNAL(clicked()),this,SLOT(buttonClicked8()));
    QObject::connect(ui->P9,SIGNAL(clicked()),this,SLOT(buttonClicked9()));
    QObject::connect(ui->nowagra,SIGNAL(clicked()),this,SLOT(clear()));
}
tictac::~tictac(){
    delete ui;
}
void tictac::buttonClicked1(){
    buttonClicked(ui->P1,1);
}
void tictac::buttonClicked2(){
    buttonClicked(ui->P2,2);
}
void tictac::buttonClicked3(){
    buttonClicked(ui->P3,3);
}
void tictac::buttonClicked4(){
    buttonClicked(ui->P4,4);
}
void tictac::buttonClicked5(){
    buttonClicked(ui->P5,5);
}
void tictac::buttonClicked6(){
    buttonClicked(ui->P6,6);
}
void tictac::buttonClicked7(){
    buttonClicked(ui->P7,7);
}
void tictac::buttonClicked8(){
    buttonClicked(ui->P8,8);
}
void tictac::buttonClicked9(){
    buttonClicked(ui->P9,9);
}
void tictac::buttonClicked(QPushButton *button, int buttton){
    buttton-=1;
    if (pole[buttton]==""){
    if (kto==kolko){
        QIcon z(":/img/img/o.bmp");
        button -> setIcon(z);
        pole[buttton]="o";
        isWin();
        QPixmap ik(":/img/img/xsmall.bmp");
        ui -> label_2 -> setPixmap(ik);
        kto = krzyzyk;
    }
    else{
        QIcon z(":/img/img/x.bmp");
        button -> setIcon(z);
        pole[buttton]="x";
        isWin();
        QPixmap ik(":/img/img/osmall.bmp");
        ui -> label_2 -> setPixmap(ik);
        kto = kolko;
    }}
}
void tictac::clear(){
    QIcon z(":/img/img/nic.bmp");
    ui->P1->setIcon(z);
    ui->P2->setIcon(z);
    ui->P3->setIcon(z);
    ui->P4->setIcon(z);
    ui->P5->setIcon(z);
    ui->P6->setIcon(z);
    ui->P7->setIcon(z);
    ui->P8->setIcon(z);
    ui->P9->setIcon(z);
    for(int i=0;i<9;i++){
        pole[i]="";
    }
    QPixmap ik(":/img/img/osmall.bmp");
    ui -> label_2 -> setPixmap(ik);
    kto = kolko;
}
void tictac::isWin(){
    bool wygrana = false;
    if((pole[0]==pole[1] && pole[1]==pole[2] && pole[2]!="") || (pole[3]==pole[4] && pole[4]==pole[5] && pole[5]!="") || (pole[6]==pole[7] && pole[7]==pole[8] && pole[8]!="")){
        wygrana = true;
    }
    else if((pole[0]==pole[3] && pole[3]==pole[6] && pole[6]!="") || (pole[1]==pole[4] && pole[4]==pole[7] && pole[7]!="") || (pole[2]==pole[5] && pole[5]==pole[8] && pole[8]!="")){
        wygrana = true;
    }
    else if((pole[0]==pole[4] && pole[4]==pole[8] && pole[8]!="") || (pole[2]==pole[4] && pole[4]==pole[6] && pole[6]!="")){
        wygrana = true;
    }
    if(wygrana){
        string msg;
        if(kto==kolko){
            msg="Wygrał gracz kółko";
        }
        else{
            msg="Wygrał gracz krzyżyk";
        }
        QMessageBox::information(this, "Tic Tac Toe", QString::fromStdString(msg));
        clear();
    }
}
