#include "board.h"

#include <iostream>
#include <algorithm> 


Board::Board() : QObject() {
	for (int i = 0; i < 8; ++i) {
        m_tiles[i][1].movedOn(new Pawn(i, 1, Colour::white));
		m_pieceW.push_back(m_tiles[i][1].getPiece());

        m_tiles[i][6].movedOn(new Pawn(i, 6, Colour::black));
		m_pieceB.push_back(m_tiles[i][6].getPiece());
	}
    m_tiles[0][0].movedOn(new Rook(0, 0, Colour::white));
	m_pieceW.push_back(m_tiles[0][0].getPiece());
    m_tiles[1][0].movedOn(new Knight(1, 0, Colour::white));
	m_pieceW.push_back(m_tiles[1][0].getPiece());
    m_tiles[2][0].movedOn(new Bishop(2, 0, Colour::white));
	m_pieceW.push_back(m_tiles[2][0].getPiece());
    m_tiles[3][0].movedOn(new Queen(3, 0, Colour::white));
	m_pieceW.push_back(m_tiles[3][0].getPiece());
    m_tiles[4][0].movedOn(new King(4, 0, Colour::white));
	m_pieceW.push_back(m_tiles[4][0].getPiece());
    m_tiles[5][0].movedOn(new Bishop(5, 0, Colour::white));
	m_pieceW.push_back(m_tiles[5][0].getPiece());
    m_tiles[6][0].movedOn(new Knight(6, 0, Colour::white));
	m_pieceW.push_back(m_tiles[6][0].getPiece());
    m_tiles[7][0].movedOn(new Rook(7, 0, Colour::white));
	m_pieceW.push_back(m_tiles[7][0].getPiece());

    m_tiles[0][7].movedOn(new Rook(0, 7, Colour::black));
	m_pieceB.push_back(m_tiles[0][7].getPiece());
    m_tiles[1][7].movedOn(new Knight(1, 7, Colour::black));
	m_pieceB.push_back(m_tiles[1][7].getPiece());
    m_tiles[2][7].movedOn(new Bishop(2, 7, Colour::black));
	m_pieceB.push_back(m_tiles[2][7].getPiece());
    m_tiles[3][7].movedOn(new Queen(3, 7, Colour::black));
	m_pieceB.push_back(m_tiles[3][7].getPiece());
    m_tiles[4][7].movedOn(new King(4, 7, Colour::black));
	m_pieceB.push_back(m_tiles[4][7].getPiece());
    m_tiles[5][7].movedOn(new Bishop(5, 7, Colour::black));
	m_pieceB.push_back(m_tiles[5][7].getPiece());
    m_tiles[6][7].movedOn(new Knight(6, 7, Colour::black));
	m_pieceB.push_back(m_tiles[6][7].getPiece());
    m_tiles[7][7].movedOn(new Rook(7, 7, Colour::black));
	m_pieceB.push_back(m_tiles[7][7].getPiece());
}



bool Board::freePath(int x_1, int y_1, int x_2, int y_2){
	if (x_1 == x_2) {
        for (int i = std::min(y_1, y_2) + 1; i < std::max(y_1, y_2); ++i) {
            if (!m_tiles[x_1][i].hasPieceColour(Colour::none)) {
				return false;
			}
		}
	}

	else if (y_1 == y_2) {
		for (int i = std::min(x_1, x_2) + 1; i < std::max(x_1, x_2); ++i) {
            if (!m_tiles[i][y_1].hasPieceColour(Colour::none)) {
				return false;
			}
		}
	}

	else if (abs(x_1 - x_2) == abs(y_1 - y_2)) {
		if ((x_1 - x_2) == (y_1 - y_2)) {
            for (int i =  1; i < abs(y_1 - y_2); ++i) {
                if (!m_tiles[std::min(x_1, x_2) + i][std::min(y_1, y_2) + i].hasPieceColour(Colour::none)) {
					return false;
				}
			}
		}
        for (int i = 1; i < abs(y_1 - y_2); ++i){
            if (!m_tiles[std::max(x_1, x_2) - i][std::min(y_1, y_2) + i].hasPieceColour(Colour::none)) {
				return false;
			}
		}
	}
	return true;
}

error Board::checkMove(int x_1, int y_1, int x_2, int y_2, Colour colour) {
    Piece* selected = m_tiles[x_1][y_1].getPiece();
    Piece* target = m_tiles[x_2][y_2].getPiece();
	if (!selected)
		return error::noSelect;
	if (selected->getColour() == oppColour(colour))
		return error::wrongColour;
	if (target && target->getColour() == colour)
		return error::illegalMove;
	error legalMove = selected->checkMove(x_2, y_2);
	if ((int)legalMove > 0)
		return legalMove;
    bool clear = freePath(x_1, y_1, x_2, y_2);
	if (!clear)
		return error::illegalMove;
	if (legalMove == error::enPassent && !target){
		if (enPassent((Pawn*)selected, x_2, y_2))
            return error::none; //might be wrong
		return error::illegalMove;
	}
	if (selected->getName() == 'p' && target && x_1 == x_2)
		return error::illegalMove;
    if(legalMove == error::enPassent)
        legalMove = error::none;
	return legalMove;
}

bool Board::enPassent(Pawn* selected, int x_2, int y_2) {
    Piece* target = m_tiles[x_2][y_2 - (int)selected->getColour()].getPiece();
	if (!target)
		return false;
	if (!(target->getName() == 'p'))
		return false;
	if (!((Pawn*)target)->m_hasHopped)
		return false;
	return true;
}

error Board::makeMove(int x_1, int y_1, int x_2, int y_2, Colour colour){
    Piece* selected = m_tiles[x_1][y_1].getPiece();
    Piece* target = m_tiles[x_2][y_2].getPiece();
	switch (checkMove(x_1, y_1, x_2, y_2, colour)) {
    case(error::none):
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
                m_tiles[x_2][y_2 - (int)selected->getColour()].movedOf();
			}
		}
		//register the move in the tiles
		if (selected->getName() == 'p')
			((Pawn*)selected)->setMoved();
        m_tiles[x_1][y_1].movedOf();
        m_tiles[x_2][y_2].movedOn(selected);
		return error::none;
	case(error::illegalMove):
		std::cout << "inserted move is illegal!\n";
		return error::illegalMove;
	case(error::outOfBounds):
		std::cout << "inserted value(s) are too small/large!\n";
		return error::outOfBounds;
	case(error::noSelect):
		std::cout << "selected piece doesn't exist\n";
		return error::noSelect;
	case(error::wrongColour):
		std::cout << "selected doesn't belong to you\n";
		return error::wrongColour;
	default:
		return error::defaultError;
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
		if ((int)checkMove(piece->getX(), piece->getY(), kingX, kingY, oppColour(colour)) <= 0)
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
        for (size_t i = 0; i < len; ++i)
			if (m_pieceW.at(i)->getX() == x && m_pieceW.at(i)->getY() == y)
				return i;
	}
	else {
		size_t len = m_pieceB.size();
        for (size_t i = 0; i < len; ++i)
			if (m_pieceB.at(i)->getX() == x && m_pieceB.at(i)->getY() == y)
				return i;
	}
	return -1;
}

void Board::deletePiece(int x,int y, Colour colour) {
    emit removedPiece(x, y, colour);
    Piece* target = m_tiles[x][y].getPiece();
	int nr = getNr(target->getX(), target->getY(), target->getColour());
	if (colour == Colour::white) {
		m_pieceW.erase(m_pieceW.begin() + nr);
	}
	else{
		m_pieceB.erase(m_pieceB.begin() + nr);
	}
    free(target);
}
