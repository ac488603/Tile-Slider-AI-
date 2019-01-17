#ifndef PIECE_H
#define PIECE_H
class piece
{
	public:
	piece(int, int, int);
	piece();
	~piece();
	int getx();
	int gety();
	int getval();
	void setx(int);
	void sety(int);
	void setval(int); 
	
	private:
	int x;
	int y;
	int value; 
}; 
#endif