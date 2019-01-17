#ifndef STRUCTURES_H
#define STRUCTURES_H
#include "grid.h"
#include<string>
#include<vector>
#include<unordered_map>


struct state
{
	state();
	state(grid *);
	state(const state&);
	~state();
	state& operator=(const state&);
	bool compare(state n);
	bool inlist(std::vector<state>);
	std::vector<state> getSuccessors(state currState);  
	void findMovable();
	void processSolution(std::vector<std::string>); 
    void processSingle(std::string direction);
	void setcost(int n ){cost = n; }
	
	//member variables
	grid  *board;
	int x;
	int y;   
	int cost;
	std::string action;
};
struct coord
{
	int x; 
	int y; 
};
struct actions
{
	actions();
	~actions(); 
	std::unordered_map<std::string, coord> directions; 
};
class node 
{
	public:
	node(); 
	node(const node&);
	~node(); 
	void updateMoves(std::string s);
	void setcost(int); 
	void setcurrState(state); 
	long int getCost();
	state getcurrState(); 
	std::vector<std::string> getMoves(); 
	node& operator=(const node& other);
	
	private:
	std::vector<std::string> moves;
	long int cost; 
	state currState;
};

#endif
