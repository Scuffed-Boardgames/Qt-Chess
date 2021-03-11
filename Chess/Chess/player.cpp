//Bernd Uijtdebroeks
#include "player.h"
#include "board.h"

Player::Player(Colour colour) : m_colour(colour), m_hasWon(false), m_isAi(false)
{}

bool Player::isWhite() {
	return m_colour == Colour::white;
}

bool Player::getWon() {
	return m_hasWon;
}

bool Player::isAi() {
	return m_isAi;
}

void Player::giveWon() {
	m_hasWon = true;
}

void Player::setAi() {
	m_isAi = true;
}