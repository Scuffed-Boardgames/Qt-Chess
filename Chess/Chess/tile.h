// Denzell Mgbokwere
#ifndef TILE_H
#define TILE_H

#include "piece.h"

class Tile{
public:
	Tile();
	Tile(Piece* piece);
	Piece* movedOf();
	void movedOn(Piece* piece);
	bool hasPieceColour(Colour colour);
	Piece* getPiece();
private:
	Piece* m_piece;
};
#endif 
