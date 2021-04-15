// Denzell Mgbokwere
#ifndef TILE_H
#define TILE_H

#include "piece.h"
#include <memory>

class Tile{
public:
	Tile();
    Tile(std::shared_ptr<Piece> piece);
    std::shared_ptr<Piece> movedOf(); // sets m_piece to null and returns the piece that was on it
    void movedOn(std::shared_ptr<Piece> piece);// sets m_piece to the given piece
	bool hasPieceColour(Colour colour);// checks if m_piece has a piece with the given colour
    std::shared_ptr<Piece> getPiece();// returns m_piece
private:
        std::shared_ptr<Piece> m_piece;
};
#endif 
