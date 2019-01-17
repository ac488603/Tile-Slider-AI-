#ifndef GRAPHICBOARD_H
#define GRAPHICBOARD_H
#include <QWidget>
#include <string>
#include <QString>
#include "mythread.h"


struct imgNode
{
    QImage img;
    int number;
};


class widget : public QWidget
{
    Q_OBJECT
public:
    widget(grid *board,QString img, QWidget *parent = 0);
    explicit widget(QWidget *parent = 0);
    void setboard(grid*);
    void setImage(QString);
    void partitionImg();
    grid* getBoard();
    ~widget();
    mythread *thread;
public slots:
    void movePiece();
protected:
    void paintEvent(QPaintEvent *);
private:
    grid *board;
    QPainter *bobRoss;
    QVector<imgNode> images;
    QImage *img;
};

#endif // GRAPHICBOARD_H
