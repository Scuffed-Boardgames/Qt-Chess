// Denzell Mgbokwere
#include "pawn.h"
#include <iostream>

Pawn::Pawn(int x, int y, Colour colour) : m_x(x), m_y(y), m_colour(colour), m_hasMoved(false), m_isTaken(false), m_hasHopped(false)
{}

bool Pawn::checkBounds(int x, int y) {
	if (x > 8 || y > 8) {
		return false;
	}
	else if (x < 1 || y < 1) {
		return false;
	}
	return true;
}

int Pawn::checkMove(int x, int y) {
	if (!checkBounds(x, y))
		return 2;

	if (m_colour == Colour::white) {
		if (m_x == x && m_y + 1 == y) {
			return 0;
		}
		else if (m_x == x && m_y + 2 == y && !m_hasMoved) {
			return -2;
		}
	}
	else{
		if (m_x == x && m_y - 1 == y) {
			return 0;
		}
		else if (m_x == x && m_y - 2 == y && !m_hasMoved) {
			return -2;
		}
	}

	return 1;
}

int Pawn::checkTake(int x, int y) {
	if (!checkBounds(x, y)) {
		return 2;
	}
	if (m_colour == Colour::white) {
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

void Pawn::toTheShadowRealm(){
	m_x = -1;
	m_y = -1;
}

Colour Pawn::getColour(){
	return m_colour;
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