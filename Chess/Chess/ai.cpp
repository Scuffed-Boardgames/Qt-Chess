#include <stdlib.h>  
#include <time.h>
#include <iostream>  
#include "ai.h"

//returns the back row for black or white
#define BACKROW(tf) ((tf)?(7):(2))

Ai::Ai(Colour colour, Board* board) {
	m_colour = colour;
	m_board = board;
}

//the order in which the ai checks moves (Denzell Mgbokwere)
int Ai::playMove() {
	bool test = checkLastRow();
	if (test)
		return 0;
	test = checkTake();
	if (test)
		return 0;
	int check = movePiece(rand() % 10);
	if (check == 0)
		return 0;
	return 1;
}

//the ai checks if it can win this move (Denzell Mgbokwere)
bool Ai::checkLastRow() {
	Pawn* pawns = m_board->getPawn(m_colour);
	for (int i = 0; i < 8; ++i) {
		if (pawns[i].getY() == (int)(4.5 + 2.5 * (int)m_colour)){
			int test = m_board->checkMove(pawns[i].getX(), pawns[i].getY(), pawns[i].getX(), pawns[i].getY() + 1 * (int)m_colour, m_colour);
			if (test == 0) {
				m_board->makeMove(pawns[i].getX(), pawns[i].getY(), pawns[i].getX(), pawns[i].getY() + 1 * (int)m_colour, m_colour);
				return true;
			}
		}
	}
	
	return false;
}

// the ai checks if it can take another pawn (Denzell Mgbokwere)
bool Ai::checkTake() {
	Pawn* pawns = m_board->getPawn(m_colour);
	for (int i = 0; i < 8; ++i) {
		int x = pawns[i].getX();
		int y = pawns[i].getY();
		int test = m_board->checkMove(x, y, x + 1, y + 1 * (int)m_colour, m_colour);
		if (test <= 0) {
			m_board->makeMove(x, y, x + 1, y + 1 * (int)m_colour, m_colour);
			return true;
		}
		test = m_board->checkMove(x, y, x - 1, y + 1 * (int)m_colour, m_colour);
		if (test <= 0) {
			m_board->makeMove(x, y, x - 1, y + 1 * (int)m_colour, m_colour);
			return true;
		}
	}
	return false;
}

// if the ai cant do anything usefull it will move a random pawn (Denzell Mgbokwere)
int Ai::movePiece(int chance) {
	Pawn* pawns = m_board->getPawn(m_colour);
	int c = 0;
	while (true) {
		int pawnNr = -1;
		while (pawnNr == -1) {
			pawnNr = rand() % 8;
			if (pawns[pawnNr].isTaken()) {
				pawnNr = -1;
			}
		}
		if (!(pawns[pawnNr].hasMoved()) && (chance > 3)) {
			int test = m_board->checkMove(pawns[pawnNr].getX(), pawns[pawnNr].getY(), pawns[pawnNr].getX(), pawns[pawnNr].getY() + 2 * (int)m_colour, m_colour);
			if (test <= 0) {
				m_board->makeMove(pawns[pawnNr].getX(), pawns[pawnNr].getY(), pawns[pawnNr].getX(), pawns[pawnNr].getY() + 2 * (int)m_colour, m_colour);
				return 0;
			}
		}
		else {
			int test = m_board->checkMove(pawns[pawnNr].getX(), pawns[pawnNr].getY(), pawns[pawnNr].getX(), pawns[pawnNr].getY() + 1 * (int)m_colour, m_colour);
			if (test <= 0) {
				m_board->makeMove(pawns[pawnNr].getX(), pawns[pawnNr].getY(), pawns[pawnNr].getX(), pawns[pawnNr].getY() + 1 * (int)m_colour, m_colour);
				return 0;
			}
		}
		++c;
		if (c > 100) {
			std::cout << "coulnd't find a valid move\n";
			return 1;
		}
	}
}