#include "pawn.h"

Pawn::Pawn(Position position, bool isWhite){
	m_isWhite = isWhite;
	m_hasMoved = false;
	m_isTaken = false;
	m_position = position;

}
int Pawn::move(Position destination) {
	m_position = destination;
	m_hasMoved = true;
	return 0;
}
int Pawn::take(Position target) {
	return 0;
}