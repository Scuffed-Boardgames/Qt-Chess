//Bernd Uijtdebroeks
#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"

class Bishop: public Piece {
public:
	Bishop(int x, int y, Colour colour);
	int checkMove(int x2, int y2); // checks if a move is a legal move for this piece
	char getName(); // returns the starting letter for a piece (in this case 'b') 
};

#endif 
