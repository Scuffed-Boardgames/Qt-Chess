//Bernd Uijtdebroeks
#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"

class Knight: public Piece {
public:
	Knight(int x, int y, Colour colour);
	int checkMove(int x2, int y2);
	char getName();
};

#endif 

