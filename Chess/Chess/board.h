//Bernd Uijtdebroeks
#ifndef BOARD_H
#define BOARD_H
#include "pawn.h"
#include "tile.h"
#include <vector>


class Board {
public:
	Board(); // Default constructor for the Board class (Bernd Uijtdebroeks)
	Pawn* checkPiece(int x, int y, Colour colour); // Checks if pawn is in given space, returns that pawn or NULL if space is empty or out of bounds (Bernd Uijtdebroeks)
	int checkMove(int x_1, int y_1, int x_2, int y_2, Colour colour); // Checks if a move is valid(<=0) or invalid(>0) (Denzell Mgbokwere)
	int makeMove(int x_1, int y_1, int x_2, int y_2, Colour colour); // Plays a move after checking if it is valid (Denzell Mgbokwere)
	void print(); // Prints the board (Bernd Uijtdebroeks)
	void removeHopped(Colour colour); // Removes the hopped status on the beginning of a move(Denzell Mgbokwere)
	std::vector<Pawn> getPawn(Colour colour); // Gives back an array of pawns
	Colour oppColour(Colour colour); // Gives back the opposite colour

private:
	// we only need an 8x8 matrix but now the coordinates overlap
	Tile m_tiles[9][9];
	std::vector<Pawn> m_pawnW;
	std::vector<Pawn> m_pawnB;
};

#endif 
