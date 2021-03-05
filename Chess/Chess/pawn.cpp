#include "pawn.h"
#include <iostream>

// makes a pawn on given position and can be black or white (Denzell Mgbokwere)
Pawn::Pawn(int x, int y, bool isWhite) {
	m_x = x;
	m_y = y;
	m_isWhite = isWhite;
	m_hasMoved = false;
	m_isTaken = false;
	m_hasHopped = false;
}
// looks if the given coordinate is a value on the board (Denzell Mgbokwere)
bool Pawn::checkBounds(int x, int y) {
	if (x > 8 || y > 8) {
		return false;
	}
	else if (x < 1 || y < 1) {
		return false;
	}
	return true;
}

// checks a move and returns if it is valid(0,-2) or invalid(>0) (Denzell Mgbokwere)
int Pawn::checkMove(int x, int y) {
	if (!checkBounds(x, y))
		return 2;

	if (m_isWhite) {
		if (m_x == x && m_y + 1 == y) {
			return 0;
		}
		else if (m_x == x && m_y + 2 == y && m_hasMoved == false) {
			return -2;
		}
	}

	else{
		if (m_x == x && m_y - 1 == y) {
			return 0;
		}
		else if (m_x == x && m_y - 2 == y && m_hasMoved == false) {
			return -2;
		}
	}

	return 1;
}
// checks a take move and returns if it is valid(-1) or invalid(>0) (Denzell Mgbokwere)
int Pawn::checkTake(int x, int y) {
	if (!checkBounds(x, y)) {
		return 2;
	}

	if (m_isWhite) {
		if ((m_x == x + 1 || m_x == x - 1) && m_y + 1 == y) {
			return -1;
		}
	}

	else{
		if ((m_x == x + 1 || m_x == x - 1) && m_y - 1 == y) {
			return -1;
		}
	}

	return 1;
}

//moves the pawn to the given destination if it is a valid move (Denzell Mgbokwere)
int Pawn::makeMove(int x, int y) {
	switch (checkMove(x, y)){
	case(-2):
		m_x = x;
		m_y = y;
		m_hasMoved = true;
		m_hasHopped = true;
		return 0;
	case(0):
		m_x = x;
		m_y = y;
		m_hasMoved = true;
		return 0;
	case(1):
		std::cout << "inserted move is illegal!\n";
		return 1;
	case(2):
		std::cout << "inserted value(s) are too small/large!\n";
		return 2;
	default:
		return 99;
	}
}

// checks if the take move is valid and executes it (Denzell Mgbokwere)
int Pawn::makeTake(int x, int y){
	switch (checkTake(x, y)) {
	case(-1):
		m_x = x;
		m_y = y;
		m_hasMoved = true;
		return -1;
	case(1):
		std::cout << "inserted move is illegal!\n";
		return 1;
	case(2):
		std::cout << "inserted value(s) are too small/large!\n";
		return 2;
	default:
		return 99;
	}
}

void Pawn::setTaken() {
	m_isTaken = true;
}

//moves a pawn to -1 -1 where it wont be found
void Pawn::toTheShadowRealm(){
	m_x = -1;
	m_y = -1;
}

bool Pawn::isWhite(){
	return m_isWhite;
}

int Pawn::getX(){
	return m_x;
}

int Pawn::getY(){
	return m_y;
}

bool Pawn::isTaken(){
	return m_isTaken;
}

bool Pawn::hasMoved(){
	return m_hasMoved;
}