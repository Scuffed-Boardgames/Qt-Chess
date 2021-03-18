//Bernd Uijtdebroeks
#include "player.h"
#include "board.h"

Player::Player(Colour colour) : m_colour(colour), m_isAi(false)
{}

bool Player::isWhite() {
	return m_colour == Colour::white;
}

bool Player::isAi() {
	return m_isAi;
}

void Player::setAi() {
	m_isAi = true;
}