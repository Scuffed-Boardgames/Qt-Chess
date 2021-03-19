//Bernd Uijtdebroeks
#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include "pawn.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "queen.h"
#include <vector>


class Board {
public:
	Board(); // Default constructor for the Board class (Bernd Uijtdebroeks)

	int checkMove(int x_1, int y_1, int x_2, int y_2, Colour colour); // Checks if a move is valid(<=0) or invalid(>0) (Denzell Mgbokwere)
	int makeMove(int x_1, int y_1, int x_2, int y_2, Colour colour); // Plays a move after checking if it is valid (Denzell Mgbokwere)
	void print(); // Prints the board (Bernd Uijtdebroeks)
	std::vector<Piece*> getPieces(Colour colour); // Gives back an array of pawns

private:
	bool enPassent(Pawn* selected, int x_2, int y_2);
	Colour oppColour(Colour colour); // Gives back the opposite colour
	void removeHopped(Colour colour); // Removes the hopped status on the beginning of a move(Denzell Mgbokwere)
	bool freePath(int x_1, int y_1, int x_2, int y_2);
	int getNr(int x, int y, Colour colour); // gives the possition in the vector for a given colour and possition
	void deletePiece(int x, int y, Colour colour); //deletes a piece if it is taken
	Tile m_tiles[8][8];
	std::vector<Piece*> m_pieceW;
	std::vector<Piece*> m_pieceB;

};

#endif 
