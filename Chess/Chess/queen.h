//Bernd Uijtdebroeks
#ifndef QUEEN_H
#define QUEEN_H
#include "bishop.h"
#include "rook.h"

class Queen: public Piece{
public:
	Queen(int x, int y, Colour colour);
	int checkMove(int x2, int y2);
	char getName();
};

#endif 

