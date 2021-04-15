#include <stdlib.h>  
#include <time.h>
#include <iostream>  
#include "ai.h"


Ai::Ai(Board* board) : m_board{ board }
{}

std::vector<int> Ai::playMove(Colour colour, Board* board) {
    std::vector<int> move;
    std::vector<Piece*> pieces = board->getPieces(colour);
	int c = 0;
	bool tried = false;
	while (true) {
		tried = false;
		c = 0;
		int pieceNr = rand() % pieces.size();
		int pieceX = pieces.at(pieceNr)->getX();
		int pieceY = pieces.at(pieceNr)->getY();
		while (!tried) {
            int x = (rand() % 8);
            int y = (rand() % 8);
            int test = (int)board->checkMove(pieceX, pieceY, x, y, colour);
			if (test <= 0) {
                test = (int)board->makeMove(pieceX, pieceY, x, y, colour);
                if (test <= 0){
                    move.push_back(pieceX);
                    move.push_back(pieceY);
                    move.push_back(x);
                    move.push_back(y);
                }
                return move;
			}
			++c;
			if (c > 100)
				tried = true;
		}
	}
}
