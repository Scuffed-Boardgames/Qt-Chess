// Denzell Mgbokwere
#ifndef AI_H
#define AI_H
#include "board.h"

class Ai{
public:
    Ai(Board* board);
    std::vector<int> playMove(Colour colour, Board* board); // Makes the ai play a randomely generated move (Denzell Mgbokwere)

private:
	Board* m_board;
};
#endif 
