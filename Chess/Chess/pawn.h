//Denzell Mgbokwere
#ifndef PAWN_H
#define PAWN_H

#include "colour.h"

class Pawn{
public:

	Pawn() = default;
	Pawn(int x, int y, Colour color);
	int checkMove(int x, int y);
	int checkTake(int x, int y);
	int makeMove(int x, int y);
	int makeTake(int x, int y);
	void setTaken();
	void toTheShadowRealm();
	int getX();
	int getY();
	bool isTaken();
	bool hasMoved();
	Colour getColour();

	bool m_hasHopped;

private:
	bool checkBounds(int x, int y);
	int m_x;
	int m_y;
	Colour m_colour;
	bool m_hasMoved;
	bool m_isTaken;
};
#endif 
