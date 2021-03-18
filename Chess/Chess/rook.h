//Bernd Uijtdebroeks
#ifndef ROOK_H
#define ROOK_H
#include "piece.h"

class Rook: public Piece {
public:
	Rook(int x, int y, Colour colour);
	int checkMove(int x2, int y2);
	char getName();
};

#endif 

