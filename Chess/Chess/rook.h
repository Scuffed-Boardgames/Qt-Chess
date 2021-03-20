//Bernd Uijtdebroeks
#ifndef ROOK_H
#define ROOK_H
#include "piece.h"

class Rook: public Piece {
public:
	Rook(int x, int y, Colour colour);
	int checkMove(int x2, int y2); // checks if a move is a legal move for this piece
	char getName(); // returns the starting letter for a piece (in this case 'R') 
};

#endif 

