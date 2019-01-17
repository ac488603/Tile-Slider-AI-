#ifndef SEARCH_H
#define SEARCH_H
#include "structures.h"
#include<queue>
class search 
{
	public:
	std::vector<std::string> Astar(state *currState, state *goal);
};
#endif
