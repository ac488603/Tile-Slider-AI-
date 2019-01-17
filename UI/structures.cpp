#include "structures.h"
#include <iterator>
#include <iostream>
state::state()
{
	board = nullptr;   
	int x = 0;
	int y = 0;   
	int cost = 0 ;
	std::string action = "";
}
state::state(grid *initial)
{
	board =  new grid(*initial); 
	findMovable();
	cost = 0;
	action = ""; 
}
state::~state(){ delete board; }

state::state(const state &other) // copy constructor
{
	this->x = other.x;
	this->y = other.y;
	this->cost = other.cost; 
	this->action = other.action;
	board = new grid(*other.board); 
}
state& state::operator=(const state& other)
{
	if(this != &other)
	{
		x = other.x;
		y = other.y;
		cost = other.cost; 
		action = other.action;
		board = new grid(*other.board); 
	}
	return *this;
}

void state::findMovable()
{
	for(int i = 0;  i < board->getSize(); i++)
	{
		for(int j = 0;  j < board->getSize();j++)
		{
			if(board->getVal(i,j) == 0)
			{
				this->x = i; this ->y = j;
			}
		}
	}
}

std::vector<state> state::getSuccessors(state currState)
{
	 std::vector<state> successors;
	 actions action;
	 std::unordered_map<std::string,coord>::iterator actionIter; 
	 for(actionIter = action.directions.begin(); actionIter != action.directions.end(); actionIter++)
	 {
		state tempState = currState; 
		coord pos = actionIter->second;
		int nextx = tempState.x + pos.x;
		int nexty = tempState.y + pos.y;
		
		if( nexty < board->getSize() && nextx < board->getSize()
			&&nextx > -1 && nexty > -1)
		{
			state nextState;
			nextState.x = nextx;
			nextState.y = nexty;
			nextState.action = actionIter->first; 
			nextState.cost = 1;  
			////modify state 
			nextState.board = new grid(*tempState.board); 
			nextState.board->moveBlank(nextx, nexty);
			successors.push_back(nextState);
		}
	 }
	return successors;
}

bool state::compare(state n)
{
	for(int i = 0;  i < board->getSize(); i++)
	{
		for(int j = 0; j < board->getSize();j++)
		{
			if(board->getVal(i,j) != n.board->getVal(i,j))
				return false;  
		}
	}
	return true; 
}

bool state::inlist(std::vector<state> explored)
{
    for(unsigned int i = 0; i < explored.size(); i++)
	{
		if(compare(explored.at(i)))
			return true; 
	}
	return false; 
}
void state::processSingle(std::string direction)
{
        actions action; //  for directions
        std::string  currMove = direction;
        coord pos =  action.directions[currMove];
        int nextx = this->x + pos.x;
        int nexty = this->y + pos.y;
        board->moveBlank(nextx,nexty);
        findMovable(); // update x and y
}

void state::processSolution(std::vector<std::string> solution)
{
	if(solution.size())
	{
	std::cout << "Processing Solution...." << std::endl<< std::endl;   
	actions action; //  for directions   
	for(int i = 0; i < solution.size(); i++ )
	{
		std::string  currMove = solution.at(i); 
		coord pos =  action.directions[currMove]; 
		int nextx = this->x + pos.x;
		int nexty = this->y + pos.y;
		board->moveBlank(nextx,nexty);
		findMovable(); // update x and y 
		std::cout << "Action: "<< currMove << std::endl; 
		board->print();  
		std::cout << std::endl;  
	}
	}
}	
///////////////////////actions /////////////////////
actions::actions()
{
	directions["EAST"] = {0 , 1};
	directions["WEST"] = {0 , -1};
	directions["SOUTH"]  = {1 , 0};
	directions["NORTH"]  = {-1, 0};
	directions["STOP"]  = {0, 0};
}
actions::~actions(){}

////////////////////////// node functions //////////////////////
node::node()
{
	this->cost = 0; 
}
node::node(const node& other)
{
	this->cost = other.cost; 
	this->currState = other.currState;
	this->moves = other.moves;
}
node::~node()
{

}
node& node::operator=(const node& other)
{
	if(this != &other)
	{
		this->cost = other.cost; 
		this->currState = other.currState;
		this->moves = other.moves;
	}
	return *this;
}

long int node::getCost()
{
	return this->cost;  
}
void node::updateMoves(std::string s)
{
	moves.push_back(s);
}
void node::setcost(int n)
{
	cost = n;
}		
void node::setcurrState(state n)
{
		currState = n;
}	
state node::getcurrState()
{
	return currState;  
}
std::vector<std::string> node::getMoves()
{
	return moves; 
}	
