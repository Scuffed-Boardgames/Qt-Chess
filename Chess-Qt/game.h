//Bernd Uijtdebroeks
#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "board.h"
#include "ai.h"

class Game {
public:
	Game(); // Creates a game
    error movePiece(const int& x1, const int& y1, const int& x2, const int& y2); // Moves a piece from x1y1 to x2y2 (Bernd Uijtdebroeks)
	void checkEnd(); // Checks if end conditions have been met (Bernd Uijtdebroeks)
	bool canMove(Colour colour); // Checks if the given player has a valid move (Denzell Mgbokwere)
    void resetBoard();
	void addTurn();
	bool hasEnded();
	void setAi(int aiCount);
    std::shared_ptr<Board> giveBoard();
	bool isAi(int player);
	int getTurn();
	int play();
    std::shared_ptr<Ai> giveAi();

private:
	void declareVictory(Colour colour); // Puts win message if white wins (Bernd Uijtdebroeks)
    Player m_player1;
    Player m_player2;
    std::shared_ptr<Board> m_board;
    std::shared_ptr<Ai> m_ai;
	int m_turn;
	bool m_hasEnded;
	size_t m_maxPieces{ 8 + 2 + 2 + 2 + 1 + 1 };
	size_t m_minPieces{ m_maxPieces - 9 };
};

#endif 
