#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QtCore>
#include "grid.h"
#include "search.h"
#include "structures.h"

class mythread: public QThread
{
    Q_OBJECT
public:
    mythread(grid*, int, QObject *parent = 0);
    explicit mythread(QObject *parent = 0);
    void run();

signals:
    void updateBoard();

private:
    state *goal;
    state *initial;
};

#endif // MYTHREAD_H
