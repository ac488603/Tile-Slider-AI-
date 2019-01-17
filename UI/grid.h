#ifndef GRID_H
#define GRID_H
#include "piece.h"
#include <string>

class grid
{
	public:
	grid(); 
	grid(int); 
	~grid(); 
	grid(grid& );
	void print();
	void printSolution(std::string currMove);
	int getSize(); 
	int getVal(int,  int); 
	void setVal(int, int, int);
	void randomizeboard(); 
	void moveBlank(int x, int y);
	piece** getboard();
	std::string findReverse(std::string move);

    private:
	void swap(piece &, piece &);
	piece ** board; 
	int size;
};

#endif
