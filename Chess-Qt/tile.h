// Denzell Mgbokwere
#ifndef TILE_H
#define TILE_H

#include "piece.h"

class Tile{
public:
	Tile();
	Tile(Piece* piece);
	Piece* movedOf(); // sets m_piece to null and returns the piece that was on it
	void movedOn(Piece* piece);// sets m_piece to the given piece
	bool hasPieceColour(Colour colour);// checks if m_piece has a piece with the given colour
	Piece* getPiece();// returns m_piece
private:
	Piece* m_piece;
};
#endif 
