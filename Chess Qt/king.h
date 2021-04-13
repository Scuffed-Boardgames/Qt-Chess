//Bernd Uijtdebroeks
#ifndef KING_H
#define KING_H
#include "piece.h"

class King : public Piece {
public:
	King(int x, int y, Colour colour);
	error checkMove(int x2, int y2); // checks if a move is a legal move for this piece
	char getName();// returns the starting letter for a piece (in this case 'K') 
};

#endif 


