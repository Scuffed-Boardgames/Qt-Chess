//Bernd Uijtdebroeks
#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"

class Queen: public Piece{
public:
	Queen(int x, int y, Colour colour);
	error checkMove(int x2, int y2); // checks if a move is a legal move for this piece
	char getName(); // returns the starting letter for a piece (in this case 'Q') 
};

#endif 

