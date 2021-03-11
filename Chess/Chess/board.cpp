#include "board.h"
#include <iostream>
#include <algorithm> 


Board::Board() {
	for (int i = 0; i < 8; ++i) {
		Pawn wPawn((i + 1), 2, Colour::white); //Fills array with pawns on line 2 for white
		m_pawnW.at(i) = wPawn;
		Pawn bPawn((i + 1), 7, Colour::black); //Fills array with pawns on line 7 for black
		m_pawnB.at(i) = bPawn;
		Tile tileW(Colour::white);
		m_tiles[i+1][2] = tileW;
		Tile tileB(Colour::black);
		m_tiles[i+1][7] = tileB;
		Tile tile;
		m_tiles[i+1][1] = tile;
		m_tiles[i+1][3] = tile;
		m_tiles[i+1][4] = tile;
		m_tiles[i+1][5] = tile;
		m_tiles[i+1][6] = tile;
		m_tiles[i+1][8] = tile;
	}
}

Pawn* Board::checkPiece(int x, int y, Colour colour) {
	if (colour == Colour::white) { // Check for white->black
		for (int i = 0; i < 8; ++i)
			if (m_pawnW.at(i).getX() == x && m_pawnW.at(i).getY() == y)
				return &m_pawnW.at(i);

	}
	else { // Check for black->white
		for (int i = 0; i < 8; ++i)
			if (m_pawnB.at(i).getX() == x && m_pawnB.at(i).getY() == y)
				return &m_pawnB.at(i);
	}
	return NULL;
}

int Board::checkMove(int x_1, int y_1, int x_2, int y_2, Colour colour) {

	Pawn* target = NULL;
	if (m_tiles[x_1][y_1].hasPieceColour(Colour::none)) {//no piece was selected
		return 3;
	}
	else if(!m_tiles[x_1][y_1].hasPieceColour(colour)){//a piece of the wrong Colour was selected
		return 4;
	}

	Pawn* selected = checkPiece(x_1, y_1, colour);

	if (x_1 == x_2) {//checks if there are any pieces between the start and destination
		for (int i = std::min(y_1, y_2) + 1; i < std::max(y_1, y_2); ++i) {
			if (!m_tiles[x_1][i].hasPieceColour(Colour::none)) {
				return 1;
			}
		}
	}

	if (m_tiles[x_2][y_2].hasPieceColour(Colour::none)){//a piece was selected and no piece on target(move)
		if (colour == Colour::white){
			if (m_tiles[x_2][y_2 - 1].hasPieceColour(oppColour(colour))){
				target = checkPiece(x_2, y_2 - 1, oppColour(colour));
			}
		}
		else{
			if (m_tiles[x_2][y_2 + 1].hasPieceColour(oppColour(colour))){
				target = checkPiece(x_2, y_2 + 1, oppColour(colour));
			}
		}
		if (target && target->m_hasHopped){
			return -1;
		}
		int test = selected->checkMove(x_2, y_2);
		if (test == -2)
			test = 0;
		return test;
	}

	if (m_tiles[x_2][y_2].hasPieceColour(oppColour(colour))) {//a piece was selected and a piece of the opposite Colour is on the target(take)
		int test = selected->checkTake(x_2, y_2);
		return test;
	}
	//a friendly piece was on the destination square
	return 1;
}

int Board::makeMove(int x_1, int y_1, int x_2, int y_2, Colour colour){
	Pawn* selected = NULL;
	if (m_tiles[x_1][y_1].hasPieceColour(colour))
		selected = checkPiece(x_1, y_1, colour);
	Pawn* target = NULL;
	if(m_tiles[x_2][y_2].hasPieceColour(oppColour(colour)))
		target = checkPiece(x_2, y_2, oppColour(colour));

	switch (checkMove(x_1, y_1, x_2, y_2, colour)) {
	case(-1):
		removeHopped(colour);
		selected->makeTake(x_2, y_2);
		if (!target){
			if(colour == Colour::white){
				target = checkPiece(x_2, y_2 - 1, oppColour(colour));
				m_tiles[x_2][y_2 - 1].movedOf();
			}
			else{
				target = checkPiece(x_2, y_2 + 1, oppColour(colour));
				m_tiles[x_2][y_2 + 1].movedOf();
			}
		}
		target->toTheShadowRealm();
		target->setTaken();
		m_tiles[x_1][y_1].movedOf();
		m_tiles[x_2][y_2].movedOn(colour);
		return 0;
	case(0):
		removeHopped(colour);
		selected->makeMove(x_2, y_2);
		m_tiles[x_1][y_1].movedOf();
		m_tiles[x_2][y_2].movedOn(colour);
		return 0;
	case(1):
		std::cout << "inserted move is illegal!\n";
		return 1;
	case(2):
		std::cout << "inserted value(s) are too small/large!\n";
		return 2;
	case(3):
		std::cout << "selected piece doesn't exist\n";
		return 3;
	case(4):
		std::cout << "selected doesn't belong to you\n";
		return 4;
	default:
		return 99;
	}
}

void Board::print() {
	std::cout << "\t";
	for (int i = 8; i >= 1; --i) {
		std::cout << " ---------------------------------\n\t";
		std::cout << i << "|";
		for (int j = 1; j <= 8; ++j) {
			if (m_tiles[j][i].hasPieceColour(Colour::white))
				std::cout << " W |";
			else if (m_tiles[j][i].hasPieceColour(Colour::black))
				std::cout << " B |";
			else
				std::cout << "   |";
		}
		std::cout << "\n\t";
	}
	std::cout << " ---------------------------------\n\t" << "   1   2   3   4   5   6   7   8 \n\n";
}

void Board::removeHopped(Colour colour) {
	if (colour == Colour::white) {
		for (int i = 0; i < 8; ++i) {
			if (m_pawnW.at(i).m_hasHopped) {
				m_pawnW.at(i).m_hasHopped = false;
				return;
			}
		}
	}
	else {
		for (int i = 0; i < 8; ++i) {
			if (m_pawnB.at(i).m_hasHopped) {
				m_pawnB.at(i).m_hasHopped = false;
				return;
			}
		}
	}
}

std::vector<Pawn> Board::getPawn(Colour colour){
	if (colour == Colour::white){
		return m_pawnW;
	}
	else{
		return m_pawnB;
	}
}

Colour Board::oppColour(Colour colour) {
	if (colour == Colour::white)
		return Colour::black;
	if (colour == Colour::black)
		return Colour::white;
	return colour;
}