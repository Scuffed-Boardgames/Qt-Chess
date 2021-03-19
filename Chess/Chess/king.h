//Bernd Uijtdebroeks
#ifndef KING_H
#define KING_H
#include "piece.h"

class King : public Piece {
public:
	King(int x, int y, Colour colour);
	int checkMove(int x2, int y2);
	char getName();
};

#endif 


