#include <stdlib.h>  
#include <time.h>
#include <iostream>  
#include "ai.h"


Ai::Ai(Colour colour, Board* board) : m_colour{ colour }, m_board{ board }
{}

int Ai::playMove() {
	int chance = rand() % 10;
	std::vector<Piece*> pieces = m_board->getPieces(m_colour);
	int c = 0;
	bool tried = false;
	while (true) {
		tried = false;
		c = 0;
		int pieceNr = rand() % pieces.size();
		int pieceX = pieces.at(pieceNr)->getX();
		int pieceY = pieces.at(pieceNr)->getY();
		while (!tried) {
			int x = (rand() % 8) + 1;
			int y = (rand() % 8) + 1;
			int test = m_board->checkMove(pieceX, pieceY, x, y, m_colour);
			if (test >= 0) {
				m_board->makeMove(pieceX, pieceY, x, y, m_colour);
				return 0;
			}
			++c;
			if (c > 100)
				tried = true;
		}
	}
}