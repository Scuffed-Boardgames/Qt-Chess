// Denzell Mgbokwere
#ifndef AI_H
#define AI_H
#include "board.h"

class Ai{
public:
    Ai(std::shared_ptr<Board> board);
    std::vector<int> playMove(Colour colour, std::shared_ptr<Board> board); // Makes the ai play a randomely generated move (Denzell Mgbokwere)

private:
    std::shared_ptr<Board> m_board;
};
#endif 
