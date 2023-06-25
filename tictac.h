
#ifndef TICTAC_H
#define TICTAC_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class tictac; }
QT_END_NAMESPACE

enum Kto{kolko,krzyzyk};

class tictac : public QMainWindow

{
    Q_OBJECT

public:
    Kto kto;
    tictac(QWidget *parent = nullptr);
    ~tictac();
private:
    Ui::tictac *ui;
    string pole[9];
private slots:
    void buttonClicked(QPushButton *button, int b);
    void buttonClicked1();
    void buttonClicked2();
    void buttonClicked3();
    void buttonClicked4();
    void buttonClicked5();
    void buttonClicked6();
    void buttonClicked7();
    void buttonClicked8();
    void buttonClicked9();
    void isWin();
    void clear();
};

#endif // TICTAC_H
