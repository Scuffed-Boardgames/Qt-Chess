//Bernd Uijtdebroeks
#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "board.h"

class Game {
public:
	Game(); // Creates a game
    error movePiece(const int& x1, const int& y1, const int& x2, const int& y2); // Moves a piece from x1y1 to x2y2 (Bernd Uijtdebroeks)
	void checkEnd(); // Checks if end conditions have been met (Bernd Uijtdebroeks)
	bool canMove(Colour colour); // Checks if the given player has a valid move (Denzell Mgbokwere)
	void addTurn();
	void print();
	bool hasEnded();
	void setAi(int aiCount);
	Board* giveBoard();
	bool isAi(int player);
	int getTurn();
	int play();

private:
	void declareVictory(Colour colour); // Puts win message if white wins (Bernd Uijtdebroeks)
	Player m_player1;
	Player m_player2;
	Board m_board;
	int m_turn;
	bool m_hasEnded;
	size_t m_maxPieces{ 8 + 2 + 2 + 2 + 1 + 1 };
	size_t m_minPieces{ m_maxPieces - 9 };
};

#endif 
