// Denzell Mgbokwere
#ifndef AI_H
#define AI_H
#include "board.h"

class Ai{
public:
	Ai(Colour colour, Board* board);
	int playMove(); // Makes the ai play a randomely generated move (Denzell Mgbokwere)

private:
	Colour m_colour;
	Board* m_board;
};
#endif 