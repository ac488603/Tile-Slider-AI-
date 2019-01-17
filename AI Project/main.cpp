#include "grid.h"
#include "search.h"
#include <stdlib.h>
#include<iostream>

int main(int argc, char** argv) 
{
	int sizeofBoard = atoi(argv[1]);
	grid *board = new grid(sizeofBoard);
	state *goal = new state(board);
	std::cout << "Goal State: " << std::endl;  
	board->print();
	board->randomizeboard();
	std::cout << "Initial State:" << std::endl;
	board->print(); 
	state *initial = new state(board);
	search agent;  
	initial->findMovable(); 
	std::vector<std::string> solution = agent.Astar(initial, goal);
	for(int i = 0; i < solution.size();i++)
		 std::cout << solution.at(i)<< ", ";
	std::cout << std::endl;   
	initial->processSolution(solution);// error with in here
	delete board;
	delete initial;
	delete goal;

	
	return 0; 
}