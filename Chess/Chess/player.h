//Bernd Uijtdebroeks
#ifndef PLAYER_H
#define PLAYER_H
#include "colour.h"
class Player {
public:
	Player() = default;
	Player(Colour colour); //Player constructor per colour
	bool isWhite();
	bool isAi();
	void setAi();

private:
	bool m_isAi;
	Colour m_colour;
};

#endif 
