#include "board.h"

#include <iostream>
#include <algorithm> 


Board::Board() {
	Tile tile;
	for (int i = 0; i < 8; ++i) {
		Pawn wPawn((i + 1), 2, Colour::white); //Fills array with pawns on line 2 for white
		Tile tileW(&wPawn);
		m_tiles[i][1] = tileW;
		m_pieceW.push_back(wPawn);

		Pawn bPawn((i + 1), 7, Colour::black); //Fills array with pawns on line 7 for black
		Tile tileB(&bPawn);
		m_pieceB.push_back(bPawn);
		m_tiles[i][6] = tileB;

		m_tiles[i][0] = tile;
		m_tiles[i][2] = tile;
		m_tiles[i][3] = tile;
		m_tiles[i][4] = tile;
		m_tiles[i][5] = tile;
		m_tiles[i][7] = tile;
	}
	Rook wLardax1(1, 1, Colour::white);
	Rook wLardax2(8, 1, Colour::white);
	Knight wHonse1(2, 1, Colour::white);
	Knight wHonse2(7, 1, Colour::white);
	Bishop wRunner1(3, 1, Colour::white);
	Bishop wRunner2(6, 1, Colour::white);
	Queen freddie(4, 1, Colour::white);
	Pawn aragorn(5, 1, Colour::white);
	m_pieceW.push_back(wLardax1);
	m_pieceW.push_back(wLardax2);
	m_pieceW.push_back(wHonse1);
	m_pieceW.push_back(wHonse2);
	m_pieceW.push_back(wRunner1);
	m_pieceW.push_back(wRunner2);
	m_pieceW.push_back(freddie);
	m_pieceW.push_back(aragorn);
}

Piece* Board::checkPiece(int x, int y, Colour colour) {
	if (colour == Colour::white) { // Check for white->black
		size_t len = m_pieceW.size();
		for (int i = 0; i < len; ++i)
			if (m_pieceW.at(i).getX() == x && m_pieceW.at(i).getY() == y)
				return &m_pieceW.at(i);

	}
	else { // Check for black->white
		size_t len = m_pieceB.size();
		for (int i = 0; i < len; ++i)
			if (m_pieceB.at(i).getX() == x && m_pieceB.at(i).getY() == y)
				return &m_pieceB.at(i);
	}
	return NULL;
}

bool Board::freePath(int x_1, int y_1, int x_2, int y_2){
	if (x_1 == x_2) {
		for (int i = std::min(y_1, y_2) + 1; i < std::max(y_1, y_2); ++i) {
			if (!m_tiles[x_1][i].hasPieceColour(Colour::none)) {
				return 1;
			}
		}
	}

	else if (y_1 == y_2) {
		for (int i = std::min(y_1, y_2) + 1; i < std::max(y_1, y_2); ++i) {
			if (!m_tiles[x_1][i].hasPieceColour(Colour::none)) {
				return 1;
			}
		}
	}

	else if (abs(x_1 - x_2) == abs(y_1 - y_2)) {
		if ((x_1 - x_2) == (y_1 - y_2)) {
			for (int i =  1; i < abs(y_1 - y_2); ++i) {
				if (!m_tiles[std::min(x_1, x_2) + i - 1][std::min(y_1, y_2) + i - 1].hasPieceColour(Colour::none)) {
					return 1;
				}
			}
		}
		for (int i = 1; i < abs(y_1 - y_2); ++i){
			if (!m_tiles[std::max(x_1, x_2) - i - 1][std::min(y_1, y_2) + i - 1].hasPieceColour(Colour::none)) {
				return 1;
			}
		}
	}
	return 0;
}

int Board::checkMove(int x_1, int y_1, int x_2, int y_2, Colour colour) {
	Piece* selected = m_tiles[x_1 - 1][y_1 - 1].getPiece();
	Piece* target = m_tiles[x_2 - 1][y_2 - 1].getPiece();
	if (!selected)
		return 3;
	if (selected->getColour() == oppColour(colour))
		return 4;
	if (target && target->getColour() == colour)
		return 1;
	int test = selected->checkMove(x_2, y_2);
	if (test > 0)
		return test;
	test = freePath(x_1, y_1, x_2, y_2);
	return test;
}

int Board::makeMove(int x_1, int y_1, int x_2, int y_2, Colour colour){
	Piece* selected = m_tiles[x_1 - 1][y_1 - 1].getPiece();
	Piece* target = m_tiles[x_2 - 1][y_2 - 1].getPiece();
	switch (checkMove(x_1, y_1, x_2, y_2, colour)) {
	case(0):
		selected->makeMove(x_2, y_2);
		if (target) {
			deletePiece(target, oppColour(colour));
		}
		m_tiles[x_1 - 1][y_1 - 1].movedOf();
		m_tiles[x_2 - 1][y_2 - 1].movedOn(selected);
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
		for (int j = 0; j < 8; ++j) {
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
//	if (colour == Colour::white) {
//		size_t len = m_pieceW.size();
//		for (int i = 0; i < len; ++i) {
//			if (m_pieceW.at(i).m_hasHopped) {
//				m_pieceW.at(i).m_hasHopped = false;
//				return;
//			}
//		}
//	}
//	else {
//		size_t len = m_pieceB.size();
//		for (int i = 0; i < len; ++i) {
//			if (m_pieceB.at(i).m_hasHopped) {
//				m_pieceB.at(i).m_hasHopped = false;
//				return;
//			}
//		}
//	}
}

std::vector<Piece> Board::getPieces(Colour colour){
	if (colour == Colour::white){
		return m_pieceW;
	}
	else{
		return m_pieceB;
	}
}

Colour Board::oppColour(Colour colour) {
	if (colour == Colour::white)
		return Colour::black;
	if (colour == Colour::black)
		return Colour::white;
	return colour;
}

int Board::getNr(int x, int y, Colour colour) {
	if (colour == Colour::white) {
		size_t len = m_pieceW.size();
		for (int i = 0; i < len; ++i)
			if (m_pieceW.at(i).getX() == x && m_pieceW.at(i).getY() == y)
				return i;
	}
	else {
		size_t len = m_pieceB.size();
		for (int i = 0; i < len; ++i)
			if (m_pieceB.at(i).getX() == x && m_pieceB.at(i).getY() == y)
				return i;
	}
	return -1;
}

void Board::deletePiece(Piece* target, Colour colour) {
	int nr = getNr(target->getX(), target->getY(), target->getColour());
	if (colour == Colour::white) {
		m_pieceW.erase(m_pieceW.begin() + nr);
	}
	else{
		m_pieceB.erase(m_pieceB.begin() + nr);
	}
}