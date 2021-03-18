//Bernd Uijtdebroeks
#ifndef ROOK_H
#define ROOK_H
#include "piece.h"

class Rook: public Piece {
public:
	int checkMove(int x2, int y2);
};

#endif 

