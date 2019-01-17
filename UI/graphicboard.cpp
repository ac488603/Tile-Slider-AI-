#include "graphicboard.h"
#include <QPainter>
#include <QMouseEvent>
#include <QImage>
#include <QPixmap>
#include <QString>
#include <iostream>

widget::widget(grid *board ,QString img, QWidget *parent) :QWidget(parent)
{
    this->board = new grid(*board);
    this->img = new QImage(img);
    this->bobRoss = new QPainter();
    this->thread = new mythread;
    partitionImg();
}
widget::widget(QWidget *parent):QWidget(parent)
{
    this->board =  NULL;
    this->img = NULL;
    this->bobRoss = new QPainter();
    update();
}

widget::~widget()
{
    delete board;
    delete img;
    delete bobRoss;
}

void widget::partitionImg()
{
    images.resize(0);
    int sizeofBoard = board->getSize();
    double partionSize = 400/ sizeofBoard;
    int id = 0;
    for(int i = 0; i < sizeofBoard; i++)
    {
         for(int j = 0; j < sizeofBoard; j++)
         {
         imgNode temp;
         temp.img = this->img->copy(QRect(i*partionSize,j*partionSize,partionSize,partionSize));
         id = id+1 % (sizeofBoard*sizeofBoard);
         temp.number =id;
         images.push_back(temp);
         }
    }
    update();
}

void widget::paintEvent(QPaintEvent *e)
{
    bobRoss->begin(this);
    QPen pen;
    pen.setColor(QColor(200,200,200));
    bobRoss->setBackgroundMode(Qt::OpaqueMode);
    if(board != NULL) {
    int sizeofBoard = board->getSize();
    double partionSize = 400/ sizeofBoard;
    int val = 0;
    for(int i = 0; i < sizeofBoard; i++){
        for(int j = 0; j < sizeofBoard; j++){
            if(board->getVal(i,j) == 0){
                bobRoss->fillRect(i*partionSize,j*partionSize,partionSize,partionSize,pen.brush());
            }else{
               val = board->getVal(i,j);
               for(int k = 0;  k < images.size(); k++)
               {
                 if(val == images[k].number)
                 {
                    bobRoss->drawImage(QRect(partionSize*i,partionSize*j,partionSize, partionSize),images[k].img);
                    bobRoss->drawLine(i*partionSize,j*partionSize,sizeofBoard*partionSize,j*partionSize);
                    bobRoss->drawLine(i*partionSize,j*partionSize,i*partionSize,sizeofBoard*partionSize);
                    break;
                 }
               }
            }
        }
    }
    bobRoss->drawLine(0,sizeofBoard*partionSize,sizeofBoard*partionSize,sizeofBoard*partionSize);
    bobRoss->drawLine(sizeofBoard*partionSize,0,sizeofBoard*partionSize,sizeofBoard*partionSize);
    bobRoss->end();
    }
    else
    {
        bobRoss->fillRect(0,400,400,400,pen.brush());
    }
     bobRoss->end();
}

void widget::setboard(grid *board)
{
    this->board = board;
    update();
}

void widget::setImage(QString img)
{
    this->img =  new QImage(img);
}

grid* widget::getBoard()
{
    return board;
}
void widget::movePiece()
{
    QPen pen;
    pen.setColor(QColor(200,200,200));
    bobRoss->fillRect(0,400,400,400,pen.brush());

}
