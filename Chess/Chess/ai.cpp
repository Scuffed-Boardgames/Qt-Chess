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
	std::vector<Pawn> pawns = m_board->getPawn(m_colour);
	size_t len = pawns.size();
	for (int i = 0; i < len; ++i) {
		int backRow = 2;
		if (m_colour == Colour::white)
			backRow = 7;
		if (pawns.at(i).getY() == backRow){
			int pawnX = pawns.at(i).getX();
			int pawnY = pawns.at(i).getY();
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
	std::vector<Pawn> pawns = m_board->getPawn(m_colour);
	size_t len = pawns.size();
	for (int i = 0; i < len; ++i) {
		int x = pawns.at(i).getX();
		int y = pawns.at(i).getY();
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
	std::vector<Pawn> pawns = m_board->getPawn(m_colour);
	int c = 0;
	while (true){
		int pawnNr = rand() % pawns.size();
		int pawnX = pawns.at(pawnNr).getX();
		int pawnY = pawns.at(pawnNr).getY();
		if ((chance > 3) && !(pawns.at(pawnNr).hasMoved())) {
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