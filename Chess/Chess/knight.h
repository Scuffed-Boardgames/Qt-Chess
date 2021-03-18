//Bernd Uijtdebroeks
#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"

class Knight: public Piece {
public:
	int checkMove(int x2, int y2);
};

#endif 

