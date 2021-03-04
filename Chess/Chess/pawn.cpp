//
#include "pawn.h"
#include <iostream>

bool Pawn::checkBounds(int x, int y) {
	if (x > 8 || y > 8) {
		std::cout << "inserted value(s) are too large!";
		return false;
	}
	else if (x < 1 || y < 1) {
		std::cout << "inserted value(s) are too small!";
		return false;
	}
	return true;
}


// makes a pawn on given position and can be black or white 
Pawn::Pawn(int x, int y, bool isWhite){
	m_isWhite = isWhite;
	m_hasMoved = false;
	m_isTaken = false;
	m_x = x;
	m_y = y;
}

void Pawn::setTaken() {
	m_isTaken = true;
}

//moves the pawn to the given destination if it is a valid move
int Pawn::move(int x, int y) {
	if (!checkBounds(x, y))
		return 2;

	if (m_isWhite) {
		if (m_x == x && m_y + 1 == y) {
			m_y = y;
			m_x = x;
			m_hasMoved = true;
			return 0;
		}
		else if (m_x == x && m_y + 2 == y && m_hasMoved == false) {
			m_y = y;
			m_x = x;
			m_hasMoved = true;
			return 0;
		}
	}

	else if (!m_isWhite) {
		if (m_x == x && m_y - 1 == y) {
			m_y = y;
			m_x = x;
			m_hasMoved = true;
			return 0;
		}
		else if (m_x == x && m_y - 2 == y && m_hasMoved == false) {
			m_y = y;
			m_x = x;
			m_hasMoved = true;
			return 0;
		}
	}

	std::cout << "inserted move is illegal!";
	return 1;
}


int Pawn::validTake(int x, int y){
	if (!checkBounds(x, y)) {
		return 2;
	}

	if (m_isWhite) {
		if ((m_x == x + 1 || m_x == x - 1) && m_y + 1 == y){
			m_x = x;
			m_y = y;
			return 0;
		}
	}

	else if (!m_isWhite) {
		if ((m_x == x + 1 || m_x == x - 1) && m_y - 1 == y){
			m_x = x;
			m_y = y;
			return 0;
		}
	}

	std::cout << "inserted move is illegal!";
	return 1;
}

bool Pawn::getClour() {
	return m_isWhite;
}

int Pawn::getX() {
	return m_x;
}

int Pawn::getY() {
	return m_y;
}