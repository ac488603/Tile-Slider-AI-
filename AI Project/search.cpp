#include "search.h"
#include "hueristics.h"
#include <queue>
#include <iostream>
struct compare  
 {  
   bool operator()( node& a, node& b)  
   {  
       return a.getCost() > b.getCost(); //create min heap  
   }  
 };  
std::vector<std::string> search::Astar(state *currState, state *goal)
{	
	int depth = 0;
	std::priority_queue<node,std::vector<node>, compare>  frontier; 
	node temp; temp.setcurrState(*currState); // node to be stored on frontier
	frontier.push(temp); 
	temp.setcost(0);
	std::vector<state> explored; // explored states
	 while(frontier.size() != 0)
		{
			node tempn(frontier.top()); // remove lowest cost node from frontier 
			frontier.pop();
			if(!tempn.getcurrState().inlist(explored)) // if state is not currently explored
			{  
				explored.push_back(tempn.getcurrState());
				if(tempn.getcurrState().compare(*goal)) // is goal state
				{
					std::cout << "Solution Found" << std::endl;
					std::cout << "Nodes Expanded: " << tempn.expanded <<std::endl;
					std::cout << "Depth: " << tempn.depth <<std::endl;
					return tempn.getMoves();
				}
			}
		
		/////////generate succesors
		   depth ++; // going down one depth 
		   std::vector<state> succesors = currState -> getSuccessors(tempn.getcurrState()); // fix getSuccessors
		   for(int i = 0;  i < succesors.size(); i++)
		   {
			   state tempstate = succesors.at(succesors.size()-i-1); 
			   node tempnode(tempn);//used to get previous moves 
			   tempnode.depth = depth; //store depth in node
			   tempnode.expanded = explored.size(); 
			   if(!tempstate.inlist(explored))
				{
					tempnode.setcurrState(tempstate); // overwrite old state
				    int costHuer = outofPlace(&tempstate,goal) + manhattanDistance(&tempstate,goal); 
				    tempnode.setcost(costHuer); 
					tempnode.updateMoves(tempstate.action); //add action to moves 
				    frontier.push(tempnode);
			    }
		    }
		}
		std::cout << "No Solution Found..." << std::endl;  
		std::vector<std::string> null;
		return null;
	}
	
