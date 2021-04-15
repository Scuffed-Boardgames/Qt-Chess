//Denzell Mgbokwere
#include"tile.h"

Tile::Tile() : m_piece(nullptr)
{}

Tile::Tile(std::shared_ptr<Piece> piece) :  m_piece(piece)
{}

std::shared_ptr<Piece> Tile::movedOf(){
    std::shared_ptr<Piece> tmp = m_piece;
	m_piece = nullptr;
	return tmp;
}

void Tile::movedOn(std::shared_ptr<Piece> piece) {
	m_piece = piece;
}

std::shared_ptr<Piece> Tile::getPiece() {
	return m_piece;
}

bool Tile::hasPieceColour(Colour colour) {
	if (!m_piece){
		return colour == Colour::none;
	}
	return m_piece->getColour() == colour;
}
