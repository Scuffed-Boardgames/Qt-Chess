#include <stdlib.h>  
#include <time.h>
#include <iostream>  
#include"ai.h"

Ai::Ai(bool isWhite, Board* board) {
	m_isWhite = isWhite;
	m_board = board;
}

int Ai::playMove() {
	bool test = checkTake();
	if (test)
		return 0;
	int check = movePiece(rand() % 10);
	if (check == 0)
		return 0;
	return 1;
}

bool Ai::checkTake() {
	if (m_isWhite) {
		Pawn* pawns = m_board->getPawnW();
		for (int i = 0; i < 8; ++i) {
			int x = pawns[i].getX();
			int y = pawns[i].getY();
			Pawn* target = m_board->checkPiece(x + 1, y + 1, !m_isWhite);
			if(!target)
				target = m_board->checkPiece(x - 1, y + 1, !m_isWhite);
			if (target) {
				m_board->movePiece(pawns[i].getX(), pawns[i].getY(), target->getX(), target->getY(), m_isWhite);
				return true;
			}

		}
	}

	else{
		Pawn* pawns = m_board->getPawnB();
		for (int i = 0; i < 8; ++i) {
			int x = pawns[i].getX();
			int y = pawns[i].getY();
			Pawn* target = m_board->checkPiece(x + 1, y - 1, !m_isWhite);
			if (!target)
				target = m_board->checkPiece(x - 1, y - 1, !m_isWhite);
			if (target) {
				m_board->movePiece(pawns[i].getX(), pawns[i].getY(), target->getX(), target->getY(), m_isWhite);
				return true;
			}
		}
	}
	return false;
}

int Ai::movePiece(int chance) {
	if (m_isWhite) {
		Pawn* pawns = m_board->getPawnW();
		int c = 0;
		while (true){
			int pawnNr = -1;
			while (pawnNr == -1) {
				pawnNr = rand() % 8;
				if (pawns[pawnNr].getStatus()) {
					pawnNr = -1;
				}
			}
			if (!(pawns[pawnNr].hasMoved()) && (chance > 3)){
				int test = m_board->movePiece(pawns[pawnNr].getX(), pawns[pawnNr].getY(), pawns[pawnNr].getX(), pawns[pawnNr].getY() + 2, m_isWhite);
				if (test == 0)
					return 0;
			}
			else{
				int test = m_board->movePiece(pawns[pawnNr].getX(), pawns[pawnNr].getY(), pawns[pawnNr].getX(), pawns[pawnNr].getY() + 1, m_isWhite);
				if (test == 0)
					return 0;
			}

			
			++c;
			if (c > 100) {
				std::cout << "coulnd't find a valid move\n";
				return 1;
			}
		}

	}

	if (!m_isWhite) {
		Pawn* pawns = m_board->getPawnB();
		int c = 0;
		while (true)
		{
			int pawnNr = -1;
			while (pawnNr == -1) {
				pawnNr = rand() % 8;
				if (pawns[pawnNr].getStatus())
					pawnNr = -1;
			}

			if (!(pawns[pawnNr].hasMoved()) && (chance > 3)) {
				int test = m_board->movePiece(pawns[pawnNr].getX(), pawns[pawnNr].getY(), pawns[pawnNr].getX(), pawns[pawnNr].getY() - 2, m_isWhite);
				if (test == 0)
					return 0;
			}
			else {
				int test = m_board->movePiece(pawns[pawnNr].getX(), pawns[pawnNr].getY(), pawns[pawnNr].getX(), pawns[pawnNr].getY() - 1, m_isWhite);
				if (test == 0)
					return 0;
			}
			++c;
			if (c > 100) {
				std::cout << "coulnd't find a valid move\n";
				return 1;
			}

		}

	}

	return 99;
}

