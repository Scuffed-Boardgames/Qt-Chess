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
	if (m_x == x && m_y + 1 == y) {
		m_y = y;
		m_x = x;
	}
	else if (m_x == x && m_y + 2 == y && m_hasMoved == false) {
		m_y = y;
		m_x = x;
	}
	else {
		std::cout << "inserted move is illegal!";
		return 1;
	}
	m_hasMoved = true;
	return 0;
}

//TODO
int Pawn::take(int x, int y) {
	return 0;
}