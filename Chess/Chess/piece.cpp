#include "piece.h"
#include <iostream>

Piece::Piece(int x, int y, Colour colour) : m_x(x), m_y(y), m_colour(colour)
{}


bool Piece::checkBounds(int x, int y) {
	if (x > 8 || y > 8) {
		return false;
	}
	else if (x < 1 || y < 1) {
		return false;
	}
	return true;
}

int Piece::makeMove(int x, int y) {
	switch (checkMove(x, y)) {
	case(0):
		m_x = x;
		m_y = y;
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

int Piece::checkMove(int x, int y) {
	if (!checkBounds(x, y))
		return 2;
	return 0;
}

Colour Piece::getColour() {
	return m_colour;
}

int Piece::getX() {
	return m_x;
}

int Piece::getY() {
	return m_y;
}