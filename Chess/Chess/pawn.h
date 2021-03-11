//Denzell Mgbokwere
#ifndef PAWN_H
#define PAWN_H

#include "colour.h"

class Pawn{
public:

	Pawn() = default;
	Pawn(int x, int y, Colour color); // Makes a pawn on given position and can be black or white
	int checkMove(int x, int y); // Checks a move and returns if it is valid(0,-2) or invalid(>0)
	int checkTake(int x, int y); // Checks a take move and returns if it is valid(-1) or invalid(>0)
	int makeMove(int x, int y); // Moves the pawn to the given destination if it is a valid move
	int makeTake(int x, int y); // Checks if the take move is valid and executes it 
	void setTaken();
	void toTheShadowRealm(); // Moves a pawn to -1 -1 where it wont be found
	int getX();
	int getY();
	bool isTaken();
	bool hasMoved();
	Colour getColour();

	bool m_hasHopped;

private:
	bool checkBounds(int x, int y); // Looks if the given coordinate is a value on the board
	int m_x;
	int m_y;
	Colour m_colour;
	bool m_hasMoved;
	bool m_isTaken;
};
#endif 
