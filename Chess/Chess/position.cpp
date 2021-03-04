#include "position.h"

Position::Position(int x, int y) : m_x{ x }, m_y{ y }{
}

void Position::move(const Position &dest) {
	m_x = dest.m_x;
	m_y = dest.m_y;
}