//Bernd Uijtdebroeks
#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
	Player() = default;
	Player(bool isWhite);
	bool isWhite();
	bool getWon();
	bool isAi();
	void giveWon();
	void setAi();

private:
	bool m_isAi;
	bool m_isWhite;
	bool m_hasWon;
};

#endif 
