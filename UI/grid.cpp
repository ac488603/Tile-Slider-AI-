#include "grid.h"
#include <iostream>
#include <random>
#include <ctime>
#include "structures.h"
#include <iterator>
#include <vector>

	piece** grid::getboard()
	{ 
		return board;
	} 
	int grid::getSize()
	{
		return size; 
	}
	grid::grid()
	{
		board = nullptr; 
		size = 0; 
	}
	//copy constructor for grid 
	grid::grid(grid& other)
	{
		this->size = other.size;
		//initialize own board
		board =  new piece*[size];
		for(int i = 0; i < getSize(); i++)
		{
			board[i] =  new piece[size]; 
		}
		for(int i = 0;  i < getSize();  i++)
		{
			for(int j = 0; j < getSize(); j++)
			{
				board[i][j] = other.getboard()[i][j]; // copy values over
			}
		}
	}

	grid::grid(int size) //  constructor
	{
		this->size = size;
		board =  new piece*[size]; 
		for(int i = 0; i < getSize(); i++)
		{
			board[i] =  new piece[size]; 
		}
		
		int value = 1;  // first square is 1 
		for(int i = 0;  i < getSize();  i++)
		{
			for(int j = 0; j < getSize(); j++)
			{
			(getboard())[i][j].setx(i);
			(getboard())[i][j].sety(j);
			(getboard())[i][j].setval(value % (getSize()* getSize())); //  last square is zero or a blank
			value++; 
			}
		}	
	}
	void grid::setVal(int x, int y, int num)
	{
		board[x][y].setval(num); 
	}
	
	void grid::moveBlank(int x, int y)
	{
		for(int i = 0;  i < size; i++)
		{
			for(int j = 0;  j < size; j++)
			{
				if(getVal(i,j) == 0)
					swap(board[i][j],board[x][y]);
			}
		}
	}
	
	grid::~grid() // deconstructor
	{ 
		for(int i = 0; i < size; i++)
		{
			delete[] board[i];
		}
		delete[] board;
	}
	
	void grid::randomizeboard()
	{		
		srand(time(0)); 
		int x = size-1; int y = size-1; //blank piece is at the last pos
		actions action; 
		std::vector<std::string> keys = {"NORTH", "SOUTH", "EAST","WEST"};
		std::string currMove = "STOP"; 
        for(int i = 0; i < (size*size); i++)
		{
				int index = rand() % 4; // select a number between 1 and 4 
				std::string nextMove =  keys.at(index);
				std::string undoMove = findReverse(currMove); // find move that will undo current move 
				if(undoMove == nextMove)
					continue;  // skip this iteration
				coord pos =  action.directions[nextMove]; 
				int nextx = x + pos.x;
				int nexty = y + pos.y;  
				if( nextx > -1 && nextx < size && nexty > -1 && nexty < size)
					moveBlank(nextx, nexty);
				else 
					continue; 
				x = nextx; 
				y = nexty;  
				currMove = nextMove;  
		}
	}
	std::string grid::findReverse(std::string move)
	{
		if(move == "NORTH")return "SOUTH";
		else if(move == "SOUTH") return "NORTH";
		else if (move == "WEST")return "EAST";
		else if(move == "EAST")return "WEST"; 
		else return "STOP";  
	}
	void grid::print()
	{
		for(int i = 0; i < getSize(); i++)
		{
			for(int j =0; j < getSize(); j++)
			{
				if(getVal(i,j)  != 0)
					std::cout << getVal(i,j) << "\t" ;
				else
					std::cout << " \t";  
			}
			std::cout << std::endl;  
		}
		std::cout << std::endl;
	}
	
	void grid::printSolution(std::string currMove)
	{
		for(int i = 0; i < getSize(); i++)
		{
			for(int j =0; j < getSize(); j++)
			{
				if(getVal(i,j)  != 0)
					std::cout << getVal(i,j) << "\t" ;
				else
					if(currMove == "NORTH")
						std::cout << ""; 
					else if (currMove =="SOUTH" )
						std::cout << "";
					else if (currMove == "EAST")
						std::cout << "";
					else 
						std::cout <<""; 
						
			}
			std::cout << std::endl;  
		}
		std::cout << std::endl;
	}
	int grid::getVal(int x, int y)
	{
		return getboard()[x][y].getval(); 
	}
	
	void grid::swap(piece &a, piece &b)
	{
		int tempVal = 0;
		tempVal = a.getval();
		a.setval(b.getval()); 
		b.setval(tempVal); 
	}
