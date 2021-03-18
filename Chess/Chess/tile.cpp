//Denzell Mgbokwere
#include"tile.h"

Tile::Tile() : m_piece(nullptr)
{}

Tile::Tile(Piece* piece) :  m_piece(piece)
{}

Piece* Tile::movedOf(){
	Piece* tmp = m_piece;
	m_piece = nullptr;
	return tmp;
}

void Tile::movedOn(Piece* piece) {
	m_piece = piece;
}

Piece* Tile::getPiece() {
	return m_piece;
}

bool Tile::hasPieceColour(Colour colour) {
	if (!m_piece){
		return colour == Colour::none;
	}
	return m_piece->getColour() == colour;
}