//Bernd Uijtdebroeks
#ifndef QUEEN_H
#define QUEEN_H
#include "bishop.h"
#include "rook.h"

class Queen: public Rook, public Bishop {
public:
	int checkMove(int x2, int y2);
};

#endif 

