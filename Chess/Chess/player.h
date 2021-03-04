//Bernd Uijtdebroeks
#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
	Player() = default;
	Player(bool isWhite);
	bool getWon();
	void giveWon();
	bool isWhite();
	void setAi();
	bool isAi();
private:
	bool m_isAi;
	bool m_isWhite;
	bool m_hasWon;
};

#endif 
