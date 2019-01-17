#include "mythread.h"
#include <QDebug>


mythread::mythread(QObject * parent): QThread(parent){}

mythread::mythread(grid* board, int size,QObject * parent): QThread(parent)
{
    grid *g = new grid(size);
    this->goal = new state(g);
    this->initial = new state(board);
    this->initial->board->print();
    this->goal->board->print();
}
void mythread::run()
{
    search *agent =  new search();
    std::vector<std::string> solution = agent->Astar(initial, goal);
     qDebug()<< solution.size() << endl;
    for(int i = 0;  i < solution.size(); i++)
    {
        initial->processSingle(solution.at(i));
        emit updateBoard(); // send signal to update board
        QThread::currentThread()->sleep(1);
    }
}

