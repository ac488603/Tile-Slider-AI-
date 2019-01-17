#include "widget.h"
#include <QApplication>
#include "graphicboard.h"
#include "grid.h"
#include "search.h"
#include "structures.h"
#include "mythread.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QValidator>
#include <unistd.h>

void init();
void randomBoard();
void solveBoard();

widget *uiBoard = NULL;
grid *board = NULL;
Widget *w = NULL;
QLineEdit *userInput = NULL;
QPushButton *random  = NULL;
QPushButton *solve   = NULL;
int sizeofBoard = 0;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w = new Widget();
    w->setWindowTitle("Fresno State Tile Slider");
    board =  new grid();
    QPushButton *sizeButton = new QPushButton();
    userInput = new QLineEdit();
    QValidator *validator = new QIntValidator(2, 6);
    userInput->setValidator(validator);

    uiBoard = new widget(w);
    uiBoard->setFixedWidth(400);
    uiBoard->setFixedHeight(400);
    w->setFixedHeight(530);
    w->setFixedWidth(430);

    QVBoxLayout *vLayout = new QVBoxLayout(w);
    QHBoxLayout *hLayout = new QHBoxLayout();
    QHBoxLayout *hLayoutinput = new QHBoxLayout();
    random  = new QPushButton();
    solve = new QPushButton();

    random->setText("Randomize Board");
    solve-> setText("Solve");
    sizeButton->setText("Size");

    //add widgets to layouts horizontal layouts
    hLayout->addWidget(random);
    hLayout->addWidget(solve);
    hLayoutinput->addWidget(userInput);
    hLayoutinput->addWidget(sizeButton);

    vLayout->addWidget(uiBoard);
    vLayout->addLayout(hLayoutinput);
    vLayout->addLayout(hLayout);

    QObject::connect(sizeButton, &QPushButton::clicked,init);
    QObject::connect(random, &QPushButton::clicked, randomBoard);
    QObject::connect(solve, &QPushButton::clicked,solveBoard);

    w->show();

    return a.exec();
}

void init()
{
    if(!userInput->text().isEmpty())
    {
    sizeofBoard = userInput->text().toInt();
    board = new grid(sizeofBoard);
    uiBoard->setboard(board);
    uiBoard->setImage(":/images/Bulldog.jpg");
    uiBoard->partitionImg();
    uiBoard->update();
    random->setEnabled(true);
    }
}

void randomBoard()
{
    if(board->getboard())
    {
    uiBoard->getBoard()->randomizeboard();
    uiBoard->update();
    random->setEnabled(false);
    }
}

void solveBoard()
{
    if(board->getboard())
    {
        solve->setEnabled(false);
        uiBoard->thread = new mythread(board,sizeofBoard);
        uiBoard->thread->start();
        random->setEnabled(true);
        solve->setEnabled(true);
    }
}
