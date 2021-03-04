//Denzell Mgbokwere
#ifndef PAWN_H
#define PAWN_H

#include "position.h"

class Pawn{
public:
	Pawn(int x, int y, bool isWhite);;
	int move(int x, int y);
	int take(int x, int y);


private:
	bool m_isWhite;
	bool m_hasMoved;
	bool m_isTaken;
	int m_x;
	int m_y;
};
#endif 
