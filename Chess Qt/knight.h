//Bernd Uijtdebroeks
#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"

class Knight: public Piece {
public:
	Knight(int x, int y, Colour colour);
	error checkMove(int x2, int y2);// checks if a move is a legal move for this piece
	char getName();// returns the starting letter for a piece (in this case 'k') 
};

#endif 

