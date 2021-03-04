//Bernd
#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
	Player() = default;
	Player(bool isWhite);
	bool getWon();
	void giveWon();
private:
	bool m_isWhite;
	bool m_hasWon;
};

#endif 
