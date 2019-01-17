#include "hueristics.h"
#include <cmath>
#include <vector>

	int outofPlace(state *curr, state *goalstate)
	{
		grid *tempBoard  = new grid(*curr->board);
		grid *goal = new grid(*goalstate->board); 
		int cost = 0; 
		for(int i = 0; i < goal->getSize(); i++)
		{
			for(int j =0; j < goal->getSize(); j++)
			{
				if(tempBoard->getVal(i,j) != goal->getVal(i,j))
				{
					cost++; 
				}
			}
		}
		delete tempBoard;
		delete goal;
		return cost; 
	}
	
	
	int manhattanDistance(state *curr, state *goalstate)
	{
		grid *tempBoard  = new grid(*curr->board);
		grid *goal = new grid(*goalstate->board); 
		int cost = 0; 
		std::vector<piece> current; 
		std::vector<piece> gol;
		
		for(int i =0;i <tempBoard->getSize();i++)
		{
			for(int j = 0;  j < tempBoard->getSize(); j++)
			{
				current.push_back(tempBoard->getboard()[i][j]);
				gol.push_back(goal->getboard()[i][j]);
			}
		}

		for(int i = 0;i < current.size();i++)
		{
			for(int j = 0;  j < current.size(); j++)
			{
				if(current.at(i).getval() ==  gol.at(j).getval())
				{
					cost += abs(current.at(i).getx()-gol.at(j).getx()) 
						 +  abs(current.at(i).gety()-gol.at(j).gety());
						break; 
				}
			}
		}		
		
		delete tempBoard;
		delete goal;
		return cost; 
	}