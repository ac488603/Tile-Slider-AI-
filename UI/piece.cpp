#include "piece.h"

	piece::piece()
	{
			x = -1;
			y = -1;
			value = -1; 
	}
	piece::piece(int x, int y, int value)
	{
		this->x = x;
		this->y = y;
		this-> value = value; 
	}
	
	int piece::getx() {return x;}
	int piece::gety(){return y;}
	int piece::getval(){return value;}
	void piece::setx(int x){this->x = x;}
	void piece::sety(int y) {this->y = y;};
	void piece::setval(int value){this->value = value; } 
	piece::~piece(){}		