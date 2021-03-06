#include"tile.h"

Tile::Tile() {
	m_hasPiece = false;
	m_pieceIsWhite = false;
}

Tile::Tile(bool isWhite) {
	m_hasPiece = true;
	m_pieceIsWhite = isWhite;
}

void Tile::movedOf(){
	m_hasPiece = false;
}

void Tile::movedOn(bool isWhite) {
	m_hasPiece = true;
	m_pieceIsWhite = isWhite;
}

bool Tile::hasPieceSame(bool isWhite) {
	if (!m_hasPiece) {
		return false;
	}
	return m_pieceIsWhite == isWhite;
}

bool Tile::hasPieceOpp(bool isWhite) {
	if (!m_hasPiece) {
		return false;
	}
	return m_pieceIsWhite != isWhite;
}