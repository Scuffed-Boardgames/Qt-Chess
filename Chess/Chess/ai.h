// Denzell Mgbokwere
#ifndef AI_H
#define AI_H
#include "board.h"

class Ai{
public:
	Ai(Colour colour, Board* board);
	int playMove();

private:
	bool checkLastRow();
	bool checkTake();
	int movePiece(int chance);
	Colour m_colour;
	Board* m_board;
};
#endif 