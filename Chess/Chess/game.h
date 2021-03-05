//Bernd Uijtdebroeks
#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "board.h"

class Game {
public:
	Game();
	int movePiece(const int& x1, const int& y1, const int& x2, const int& y2);
	void checkEnd();
	bool canMove(bool isWhite);
	void addTurn();
	void print();
	bool hasEnded();
	void setAi(int aiCount);
	Board* giveBoard();
	bool isAi(int player);
	int getTurn();
	void declareWinner(bool isWhite);

private:
	void declareVictory();
	Player m_player1;
	Player m_player2;
	Board m_board;
	int m_turn;
	bool m_hasEnded;
};

#endif 
