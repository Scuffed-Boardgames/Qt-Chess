//Bernd Uijtdebroeks
#include "player.h"
#include "board.h"

Player::Player(bool isWhite) { //Player constructor per colour
	m_isWhite = isWhite;
	m_hasWon = false;
	m_isAi = false;
}

bool Player::getWon() { //Returns if the players has won or not
	return m_hasWon;
}

void Player::giveWon() { //Changes hasWon to true
	m_hasWon = true;
}

bool Player::isWhite() {
	return m_isWhite;
}

void Player::setAi() {
	m_isAi = true;
}

bool Player::isAi() {
	return m_isAi;
}
