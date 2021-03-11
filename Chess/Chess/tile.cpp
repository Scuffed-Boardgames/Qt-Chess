//Denzell Mgbokwere
#include"tile.h"

Tile::Tile() : m_colour(Colour::none) 
{}

Tile::Tile(Colour colour) : m_colour(colour) 
{}

void Tile::movedOf(){
	m_colour = Colour::none;
}

void Tile::movedOn(Colour colour) {
	m_colour = colour;
}

bool Tile::hasPieceColour(Colour colour) {
	return m_colour == colour;
}
