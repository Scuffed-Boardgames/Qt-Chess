//Bernd Uijtdebroeks
#include "player.h"
#include "board.h"

Player::Player(Colour colour) { //Player constructor per colour
	m_colour = colour;
	m_hasWon = false;
	m_isAi = false;
}

bool Player::isWhite() {
	return m_colour == Colour::white;
}

bool Player::getWon() { //Returns if the players has won or not
	return m_hasWon;
}

bool Player::isAi() {
	return m_isAi;
}

void Player::giveWon() { //Changes hasWon to true
	m_hasWon = true;
}

void Player::setAi() {
	m_isAi = true;
}