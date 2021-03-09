//Bernd Uijtdebroeks
#ifndef PLAYER_H
#define PLAYER_H
#include "colour.h"
class Player {
public:
	Player() = default;
	Player(Colour colour);
	bool isWhite();
	bool getWon();
	bool isAi();
	void giveWon();
	void setAi();

private:
	bool m_isAi;
	Colour m_colour;
	bool m_hasWon;
};

#endif 
