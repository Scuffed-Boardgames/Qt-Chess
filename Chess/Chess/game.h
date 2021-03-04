//Bernd Uijtdebroeks
#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "board.h"

class Game {
public:
	Game();
	void checkEnd();
	int movePiece(const int &x1, const int &y1, const int &x2, const int &y2);
	bool hasEnded();
	void setAi(int aiCount);
	void addTurn();
	Board* giveBoard();
	bool isAi(int player);
	int getTurn();
	void print();
private:
	void whiteVictory();
	void blackVictory();
	Player m_player1;
	Player m_player2;
	Board m_board;
	int m_turn;
	bool m_hasEnded;
};

#endif 
