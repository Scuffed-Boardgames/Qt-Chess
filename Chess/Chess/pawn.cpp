//Denzell Mgbokwere
#include "pawn.h"
#include <iostream>

// makes a pawn on given position and can be black or white 
Pawn::Pawn(int x, int y, bool isWhite){
	m_isWhite = isWhite;
	m_hasMoved = false;
	m_isTaken = false;
	m_x = x;
	m_y = y;
}

//moves the pawn to the given destination if it is a valid move
int Pawn::move(int x, int y) {

	if (x > 8 || y > 8) {
		std::cout << "inserted value(s) are too large!";
		return 2;
	}

	else if (x < 1 || y < 1) {
		std::cout << "inserted value(s) are too small!";
		return 2;
	}

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

	if (!m_isWhite) {
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
	else {
		std::cout << "inserted move is illegal!";
		return 1;
	}
	
}

//TODO
int Pawn::take(int x, int y) {
	return 0;
}

int Pawn::getX() {
	return m_x;
}

int Pawn::getY() {
	return m_y;
}