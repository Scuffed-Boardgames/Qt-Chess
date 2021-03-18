//Bernd Uijtdebroeks
#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"

class Bishop: public Piece {
public:
	Bishop(int x, int y, Colour colour);
	int checkMove(int x2, int y2);
	char getName();
};

#endif 
