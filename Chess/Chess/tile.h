// Denzell Mgbokwere
#ifndef TILE_H
#define TILE_H

#include "colour.h"

class Tile{
public:
	Tile();
	Tile(Colour colour);
	void movedOf();
	void movedOn(Colour colour);
	bool hasPieceColour(Colour colour);
	Colour m_colour;
private:
};
#endif 
