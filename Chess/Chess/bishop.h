//Bernd Uijtdebroeks
#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"

class Bishop: public Piece {
public:
	int checkMove(int x2, int y2);
};

#endif 
