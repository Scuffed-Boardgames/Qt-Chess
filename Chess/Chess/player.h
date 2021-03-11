//Bernd Uijtdebroeks
#ifndef PLAYER_H
#define PLAYER_H
#include "colour.h"
class Player {
public:
	Player() = default;
	Player(Colour colour); //Player constructor per colour
	bool isWhite();
	bool getWon(); //Returns if the players has won or not
	bool isAi();
	void giveWon(); //Changes hasWon to true
	void setAi();

private:
	bool m_isAi;
	Colour m_colour;
	bool m_hasWon;
};

#endif 
