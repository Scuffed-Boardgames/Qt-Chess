//Denzell Mgbokwere
#ifndef PIECE_H
#define PIECE_H

#include "colour.h"

class Piece {
public:
	
	Piece() = default;
	Piece(int x, int y, Colour colour); // Makes a pawn on given position and can be black or white

	int makeMove(int x, int y); // Moves the pawn to the given destination if it is a valid move

	int getX(); //getter for the x coordinate
	int getY(); //getter for the y coordinate
	Colour getColour(); //getter for colour
	virtual char getName() = 0;
	virtual int checkMove(int x, int y);

private:
	bool checkBounds(int x, int y); // Looks if the given coordinate is a value on the board
	int m_x;
	int m_y;
	Colour m_colour;
};
#endif 

