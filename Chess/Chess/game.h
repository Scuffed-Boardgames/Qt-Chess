//Bernd Uijtdebroeks
#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "board.h"

class Game {
public:
	Game() = default;
	Game(int white);
	void checkEnd();
	int movePiece(int x1, int y1, int x2, int y2);
	void whiteVictory();
	void blackVictory();
private:
	Player m_player1;
	Player m_player2;
	Board m_board;
	int m_turn;
	bool m_hasEnded;
};

#endif 
