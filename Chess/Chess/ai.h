// Denzell Mgbokwere
#ifndef AI_H
#define AI_H
#include "board.h"

class Ai{
public:
	Ai(Colour colour, Board* board);
	int playMove(); // The order in which the ai checks moves (Denzell Mgbokwere)

private:
	bool checkLastRow(); // The ai checks if it can win this move (Denzell Mgbokwere)
	bool checkTake(); // The ai checks if it can take another pawn (Denzell Mgbokwere)
	int movePiece(int chance); // If the ai cant do anything usefull it will move a random pawn (Denzell Mgbokwere)
	Colour m_colour;
	Board* m_board;
};
#endif 