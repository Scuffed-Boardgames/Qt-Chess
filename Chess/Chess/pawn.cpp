//Denzell Mgbokwere
#include "pawn.h"
#include <iostream>

// makes a pawn on given position and can be black or white 
Pawn::Pawn(Position position, bool isWhite){
	m_isWhite = isWhite;
	m_hasMoved = false;
	m_isTaken = false;
	m_position = position;
}

//moves the pawn to the given destination if it is a valid move
int Pawn::move(Position destination) {
	if (m_position.m_x == destination.m_x && m_position.m_y + 1 == destination.m_y)
		m_position = destination;
	else if (m_position.m_x == destination.m_x && m_position.m_y + 2 == destination.m_y && m_hasMoved == false)
		m_position = destination;
	else {
		std::cout << "inserted move is illegal!";
		return 1;
	}
	m_hasMoved = true;
	return 0;
}

//TODO
int Pawn::take(Position target) {
	return 0;
}