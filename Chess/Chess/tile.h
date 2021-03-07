// Denzell Mgbokwere
#ifndef TILE_H
#define TILE_H

class Tile{
public:
	Tile();
	Tile(bool isWhite);
	void movedOf();
	void movedOn(bool isWhite);
	bool hasPieceSame(bool isWhite);
	bool hasPieceOpp(bool isWhite);
	bool m_hasPiece;
	bool m_pieceIsWhite;
private:
};
#endif 
