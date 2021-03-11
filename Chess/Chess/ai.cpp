#include <stdlib.h>  
#include <time.h>
#include <iostream>  
#include "ai.h"


Ai::Ai(Colour colour, Board* board) : m_colour{ colour }, m_board{ board }
{}

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

bool Ai::checkLastRow() {
	Pawn* pawns = m_board->getPawn(m_colour);
	for (int i = 0; i < 8; ++i) {
		int backRow = 2;
		if (m_colour == Colour::white)
			backRow = 7;
		if (pawns[i].getY() == backRow){
			int pawnX = pawns[i].getX();
			int pawnY = pawns[i].getY();
			int test = m_board->checkMove(pawnX, pawnY, pawnX, pawnY + (int)m_colour, m_colour);
			if (test == 0) {
				m_board->makeMove(pawnX, pawnY, pawnX, pawnY + (int)m_colour, m_colour);
				return true;
			}
		}
	}
	
	return false;
}

bool Ai::checkTake() {
	Pawn* pawns = m_board->getPawn(m_colour);
	for (int i = 0; i < 8; ++i) {
		int x = pawns[i].getX();
		int y = pawns[i].getY();
		int test = m_board->checkMove(x, y, x + 1, y + (int)m_colour, m_colour);
		if (test <= 0) {
			m_board->makeMove(x, y, x + 1, y + (int)m_colour, m_colour);
			return true;
		}
		test = m_board->checkMove(x, y, x - 1, y + (int)m_colour, m_colour);
		if (test <= 0) {
			m_board->makeMove(x, y, x - 1, y + (int)m_colour, m_colour);
			return true;
		}
	}
	return false;
}

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
		int pawnX = pawns[pawnNr].getX();
		int pawnY = pawns[pawnNr].getY();
		if ((chance > 3) && !(pawns[pawnNr].hasMoved())) {
			int test = m_board->checkMove(pawnX, pawnY, pawnX, pawnY + 2 * (int)m_colour, m_colour);
			if (test <= 0) {
				m_board->makeMove(pawnX, pawnY, pawnX, pawnY + 2 * (int)m_colour, m_colour);
				return 0;
			}
		}
		else {
			int test = m_board->checkMove(pawnX, pawnY, pawnX, pawnY + (int)m_colour, m_colour);
			if (test <= 0) {
				m_board->makeMove(pawnX, pawnY, pawnX, pawnY + (int)m_colour, m_colour);
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