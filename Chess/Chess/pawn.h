//Denzell Mgbokwere
#ifndef PAWN_H
#define PAWN_H

#include "colour.h"
#include "piece.h"

class Pawn : public Piece {
public:
	Pawn(int x, int y, Colour color); // Makes a pawn on given position and can be black or white

	int checkMove(int x, int y); // Checks a move and returns if it is valid(0,-2) or invalid(>0)
	
	bool hasMoved(); //getter for the hasmoved bool

	char getName();

	bool m_hasHopped;

private:
	bool m_hasMoved;
};
#endif 
