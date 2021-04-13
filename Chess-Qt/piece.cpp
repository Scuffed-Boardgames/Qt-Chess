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

error Piece::makeMove(int x, int y) {
	switch (checkMove(x, y)) {
	case(error::none):
		m_x = x;
		m_y = y;
		return error::none;
	case(error::illegalMove):
		std::cout << "inserted move is illegal!\n";
		return error::illegalMove;
	case(error::outOfBounds):
		std::cout << "inserted value(s) are too small/large!\n";
		return error::outOfBounds;
	default:
		return error::defaultError;
	}
}

error Piece::checkMove(int x, int y) {
	if (!checkBounds(x, y))
		return error::outOfBounds;
	return error::none;
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