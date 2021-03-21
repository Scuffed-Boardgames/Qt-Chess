#include "board.h"

#include <iostream>
#include <algorithm> 


Board::Board() {
	for (int i = 0; i < 8; ++i) {
		Pawn* wPawn = new Pawn((i + 1), 2, Colour::white); //Fills array with pawns on line 2 for white
		m_tiles[i][1].movedOn(wPawn);
		m_pieceW.push_back(wPawn);

		Pawn* bPawn = new Pawn((i + 1), 7, Colour::black); //Fills array with pawns on line 7 for black
		m_tiles[i][6].movedOn(bPawn);
		m_pieceB.push_back(bPawn);
	}
	Rook* wLardax1 = new Rook(1, 1, Colour::white);
	Rook* wLardax2 = new Rook(8, 1, Colour::white);
	Knight* wHonse1 = new Knight(2, 1, Colour::white);
	Knight* wHonse2 = new Knight(7, 1, Colour::white);
	Bishop* wRunner1 = new Bishop(3, 1, Colour::white);
	Bishop* wRunner2 = new Bishop(6, 1, Colour::white);
	Queen* wFreddie = new Queen(4, 1, Colour::white);
	King* wMeruem = new King(5, 1, Colour::white);
	m_tiles[0][0].movedOn(wLardax1);
	m_tiles[1][0].movedOn(wHonse1);
	m_tiles[2][0].movedOn(wRunner1);
	m_tiles[3][0].movedOn(wFreddie);
	m_tiles[4][0].movedOn(wMeruem);
	m_tiles[5][0].movedOn(wRunner2);
	m_tiles[6][0].movedOn(wHonse2);
	m_tiles[7][0].movedOn(wLardax2);

	m_pieceW.push_back(wLardax1);
	m_pieceW.push_back(wLardax2);
	m_pieceW.push_back(wHonse1);
	m_pieceW.push_back(wHonse2);
	m_pieceW.push_back(wRunner1);
	m_pieceW.push_back(wRunner2);
	m_pieceW.push_back(wFreddie);
	m_pieceW.push_back(wMeruem);

	Rook* bLardax1 = new Rook(1, 8, Colour::black);
	Rook* bLardax2 = new Rook(8, 8, Colour::black);
	Knight* bHonse1 = new Knight(2, 8, Colour::black);
	Knight* bHonse2 = new Knight(7, 8, Colour::black);
	Bishop* bRunner1 = new Bishop(3, 8, Colour::black);
	Bishop* bRunner2 = new Bishop(6, 8, Colour::black);
	Queen* bFreddie = new Queen(4, 8, Colour::black);
	King* bMeruem = new King(5, 8, Colour::black);
	m_tiles[0][7].movedOn(bLardax1);
	m_tiles[1][7].movedOn(bHonse1);
	m_tiles[2][7].movedOn(bRunner1);
	m_tiles[3][7].movedOn(bFreddie);
	m_tiles[4][7].movedOn(bMeruem);
	m_tiles[5][7].movedOn(bRunner2);
	m_tiles[6][7].movedOn(bHonse2);
	m_tiles[7][7].movedOn(bLardax2);

	m_pieceB.push_back(bLardax1);
	m_pieceB.push_back(bLardax2);
	m_pieceB.push_back(bHonse1);
	m_pieceB.push_back(bHonse2);
	m_pieceB.push_back(bRunner1);
	m_pieceB.push_back(bRunner2);
	m_pieceB.push_back(bFreddie);
	m_pieceB.push_back(bMeruem);
}



bool Board::freePath(int x_1, int y_1, int x_2, int y_2){
	if (x_1 == x_2) {
		for (int i = std::min(y_1, y_2) + 1; i < std::max(y_1, y_2); ++i) {
			if (!m_tiles[x_1 - 1][i - 1].hasPieceColour(Colour::none)) {
				return false;
			}
		}
	}

	else if (y_1 == y_2) {
		for (int i = std::min(x_1, x_2) + 1; i < std::max(x_1, x_2); ++i) {
			if (!m_tiles[i - 1][y_1 - 1].hasPieceColour(Colour::none)) {
				return false;
			}
		}
	}

	else if (abs(x_1 - x_2) == abs(y_1 - y_2)) {
		if ((x_1 - x_2) == (y_1 - y_2)) {
			for (int i =  1; i < abs(y_1 - y_2); ++i) {
				if (!m_tiles[std::min(x_1, x_2) + i - 1][std::min(y_1, y_2) + i - 1].hasPieceColour(Colour::none)) {
					return false;
				}
			}
		}
		for (int i = 1; i < abs(y_1 - y_2); ++i){
			if (!m_tiles[std::max(x_1, x_2) - i - 1][std::min(y_1, y_2) + i - 1].hasPieceColour(Colour::none)) {
				return false;
			}
		}
	}
	return true;
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
	int legalMove = selected->checkMove(x_2, y_2);
	if (legalMove > 0)
		return legalMove;
	bool clear = freePath(x_1, y_1, x_2, y_2);
	if (!clear)
		return 1;
	if (legalMove == -1 && !target){
		if (enPassent((Pawn*)selected, x_2, y_2))
			return -1;
		return 1;
	}
	if (selected->getName() == 'p' && target && x_1 == x_2)
		return 1;
	return legalMove;
}

bool Board::enPassent(Pawn* selected, int x_2, int y_2) {
	int sX = selected->getX();
	int sY = selected->getY();

	Piece* target = m_tiles[x_2 - 1][y_2 - 1 - (int)selected->getColour()].getPiece();
	if (!target)
		return false;
	if (!(target->getName() == 'p'))
		return false;
	if (!((Pawn*)target)->m_hasHopped)
		return false;
	return true;
}

int Board::makeMove(int x_1, int y_1, int x_2, int y_2, Colour colour){
	Piece* selected = m_tiles[x_1 - 1][y_1 - 1].getPiece();
	Piece* target = m_tiles[x_2 - 1][y_2 - 1].getPiece();
	switch (checkMove(x_1, y_1, x_2, y_2, colour)) {
	case(0):
		removeHopped(colour);
		selected->makeMove(x_2, y_2);
		// if there is a target, take it
		if(target){
			deletePiece(x_2, y_2, oppColour(colour));
		}
		if (abs(y_1 - y_2) == 2 && selected->getName() == 'p')
			((Pawn*)selected)->m_hasHopped = true;
		//en passent
		if (selected->getName() == 'p' && !target) {
			if (enPassent((Pawn*)selected, x_2, y_2)) {
				deletePiece(x_2, y_2 - (int)selected->getColour(), oppColour(colour));
				m_tiles[x_2 - 1][y_2 - 1 - (int)selected->getColour()].movedOf();
			}
		}
		//register the move in the tiles
		if (selected->getName() == 'p')
			((Pawn*)selected)->setMoved();
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
	for (int i = 7; i >= 0; --i) {
		std::cout << " -----------------------------------------\n\t";
		std::cout << i+1 << "|";
		for (int j = 0; j < 8; ++j) {
			if (m_tiles[j][i].hasPieceColour(Colour::white)) {
				char name = m_tiles[j][i].getPiece()->getName();
				std::cout << " " << name << "W |";
			}
			else if (m_tiles[j][i].hasPieceColour(Colour::black)) {
				char name = m_tiles[j][i].getPiece()->getName();
				std::cout << " " << name << "B |";
			}
			else
				std::cout << "    |";
		}
		std::cout << "\n\t";
	}
	std::cout << " -----------------------------------------\n\t" << "    1    2    3    4    5    6    7    8 \n\n";
}

void Board::removeHopped(Colour colour) {
	std::vector<Piece*> pieces = getPieces(oppColour(colour));
	for (Piece* piece : pieces) {
		if(piece->getName() == 'p'){
			if (((Pawn*)piece)->m_hasHopped) {
				((Pawn*)piece)->m_hasHopped = false;
				return;
			}
		}
	}
}

bool Board::checkCheck(Colour colour) { // not yet implemented
	King* king = getKing(colour);
	int kingX = king->getX();
	int kingY = king->getY();
	std::vector<Piece*> pieces = getPieces(oppColour(colour));
	for (Piece* piece : pieces){
		if (checkMove(piece->getX(), piece->getY(), kingX, kingY, oppColour(colour)) <= 0)
			return true;
	}
	return false;
}

King* Board::getKing(Colour colour) { // not yet implemented
	std::vector<Piece*> pieces = getPieces(oppColour(colour));
	for (Piece* piece : pieces) {
		if (piece->getName() == 'K') {
			return (King*)piece;
		}
	}
	King* king = new King(0, 0, Colour::none);
	return king;
}

std::vector<Piece*> Board::getPieces(Colour colour){
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
			if (m_pieceW.at(i)->getX() == x && m_pieceW.at(i)->getY() == y)
				return i;
	}
	else {
		size_t len = m_pieceB.size();
		for (int i = 0; i < len; ++i)
			if (m_pieceB.at(i)->getX() == x && m_pieceB.at(i)->getY() == y)
				return i;
	}
	return -1;
}

void Board::deletePiece(int x,int y, Colour colour) {
	Piece* target = m_tiles[x - 1][y - 1].getPiece();
	int nr = getNr(target->getX(), target->getY(), target->getColour());
	if (colour == Colour::white) {
		m_pieceW.erase(m_pieceW.begin() + nr);
	}
	else{
		m_pieceB.erase(m_pieceB.begin() + nr);
	}
	delete target;
}
