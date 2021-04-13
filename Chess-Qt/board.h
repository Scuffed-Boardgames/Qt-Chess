//Bernd Uijtdebroeks
#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include "error.h"
#include "pawn.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "queen.h"
#include "king.h"
#include <vector>
#include <QObject>

class Board : public QObject {
    Q_OBJECT
public:
	Board(); // Default constructor for the Board class (Bernd Uijtdebroeks)
	error checkMove(int x_1, int y_1, int x_2, int y_2, Colour colour); // Checks if a move is valid(<=0) or invalid(>0) (Denzell Mgbokwere)
    error makeMove(int x_1, int y_1, int x_2, int y_2, Colour colour); // Plays a move after checking if it is valid (Denzell Mgbokwere)
	void print();	// Prints the board (Bernd Uijtdebroeks)
	std::vector<Piece*> getPieces(Colour colour); // Gives back an array of pawns (Denzell Mgbokwere)
	bool checkCheck(Colour colour); // checks wether the king of colour is in check (Denzell Mgbokwere)
signals:
    void removedPiece(int x, int y, Colour colour);
private:
	King* getKing(Colour colour); //returns the king of the given colour
	bool enPassent(Pawn* selected, int x_2, int y_2); // checks if the given move is a legal en passent move (Denzell Mgbokwere)
	Colour oppColour(Colour colour); // Gives back the opposite colour
	void removeHopped(Colour colour); // Removes the hopped status on the beginning of a move (Denzell Mgbokwere)
	bool freePath(int x_1, int y_1, int x_2, int y_2); // checks if there are other pieces in the way of the given move (Denzell Mgbokwere)
	int getNr(int x, int y, Colour colour); // gives the possition in the vector for a given colour and possition
	void deletePiece(int x, int y, Colour colour); //deletes a piece if it is taken (Denzell Mgbokwere)
	Tile m_tiles[8][8];
	std::vector<Piece*> m_pieceW;
	std::vector<Piece*> m_pieceB;

};

#endif 
