//Bernd Uijtdebroeks
#include "player.h"
#include "board.h"

Player::Player(bool isWhite) { //Player constructor per colour
	m_isWhite = isWhite;
	m_hasWon = false;
}

bool Player::getWon() { //Return if the players has won or not
	return m_hasWon;
}

void Player::giveWon() {
	m_hasWon = true;
}