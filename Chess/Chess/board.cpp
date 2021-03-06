#include "board.h"
#include <iostream>

#define WHITE true
#define BLACK false

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

// Default constructor for the Board class (Bernd Uijtdebroeks)
Board::Board() {
	for (int i = 0; i < 8; ++i) {
		Pawn wPawn((i + 1), 2, WHITE); //Fills array with pawns on line 2 for white
		m_pawnW[i] = wPawn;
		Pawn bPawn((i + 1), 7, BLACK); //Fills array with pawns on line 7 for black
		m_pawnB[i] = bPawn;
		Tile tileW(WHITE);
		m_tiles[i+1][2] = tileW;
		Tile tileB(BLACK);
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

// Checks if pawn is in given space, returns that pawn or NULL if space is empty or out of bounds (Bernd Uijtdebroeks)
Pawn* Board::checkPiece(int x, int y, bool isWhite) {
	if (!isWhite) { // Check for white->black
		for (int i = 0; i < 8; ++i)
			if (m_pawnB[i].getX() == x && m_pawnB[i].getY() == y)
				return &m_pawnB[i];
	}
	else { // Check for black->white
		for (int i = 0; i < 8; ++i)
			if (m_pawnW[i].getX() == x && m_pawnW[i].getY() == y)
				return &m_pawnW[i];
	}
	return NULL;
}

// checks if a move is valid(<=0) or invalid(>0) (Denzell Mgbokwere)
int Board::checkMove(int x_1, int y_1, int x_2, int y_2, bool isWhite) {

	Pawn* target = NULL;
	if (!m_tiles[x_1][y_1].m_hasPiece) {//no piece was selected
		return 3;
	}
	else if(m_tiles[x_1][y_1].hasPieceOpp(isWhite)){//a piece of the wrong colour was selected
		return 4;
	}

	Pawn* selected = checkPiece(x_1, y_1, isWhite);

	if (x_1 == x_2) {//checks if there are any pieces between the start and destination
		for (int i = min(y_1, y_2) + 1; i < max(y_1, y_2); ++i) {
			if (m_tiles[x_1][i].m_hasPiece) {
				return 1;
			}
		}
	}

	if (!m_tiles[x_2][y_2].m_hasPiece){//a piece was selected and no piece on target(move)
		if (isWhite){
			if (m_tiles[x_2][y_2 - 1].hasPieceOpp(isWhite)){
				target = checkPiece(x_2, y_2 - 1, !isWhite);
			}
		}
		else{
			if (m_tiles[x_2][y_2 + 1].hasPieceOpp(isWhite)) {
				target = checkPiece(x_2, y_2 + 1, !isWhite);
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

	if (m_tiles[x_2][y_2].hasPieceOpp(isWhite)) {//a piece was selected and a piece of the opposite colour is on the target(take)
		int test = selected->checkTake(x_2, y_2);
		return test;
	}
	//a friendly piece was on the destination square
	return 1;
}

// plays a move after checking if it is valid (Denzell Mgbokwere)
int Board::makeMove(int x_1, int y_1, int x_2, int y_2, bool isWhite){
	Pawn* selected = NULL;
	if (m_tiles[x_1][y_1].hasPieceSame(isWhite))
		selected = checkPiece(x_1, y_1, isWhite);
	Pawn* target = NULL;
	if(m_tiles[x_2][y_2].hasPieceOpp(isWhite))
		target = checkPiece(x_2, y_2, !isWhite);

	switch (checkMove(x_1, y_1, x_2, y_2, isWhite)) {
	case(-1):
		removeHopped(isWhite);
		selected->makeTake(x_2, y_2);
		if (!target){
			if(isWhite){
				target = checkPiece(x_2, y_2 - 1, !isWhite);
				m_tiles[x_2][y_2 - 1].movedOf();
			}
			else{
				target = checkPiece(x_2, y_2 + 1, !isWhite);
				m_tiles[x_2][y_2 + 1].movedOf();
			}
		}
		target->toTheShadowRealm();
		target->setTaken();
		m_tiles[x_1][y_1].movedOf();
		m_tiles[x_2][y_2].movedOn(isWhite);
		return 0;
	case(0):
		removeHopped(isWhite);
		selected->makeMove(x_2, y_2);
		m_tiles[x_1][y_1].movedOf();
		m_tiles[x_2][y_2].movedOn(isWhite);
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
			if (m_tiles[j][i].hasPieceSame(WHITE))
				std::cout << " W |";
			else if (m_tiles[j][i].hasPieceSame(BLACK))
				std::cout << " B |";
			else
				std::cout << "   |";
		}
		std::cout << "\n\t";
	}
	std::cout << " ---------------------------------\n\t" << "   1   2   3   4   5   6   7   8 \n\n";
}

int Board::countWhitePawns() {
	int count = 0;
	for (int i = 0; i < 8; ++i)
		if (!m_pawnW[i].isTaken()) {
			count += 1;
		}
	return count;
}

int Board::countBlackPawns() {
	int count = 0;
	for (int i = 0; i < 8; ++i)
		if (!m_pawnB[i].isTaken()) {
			count += 1;
		}
	return count;
}

//removes the hopped status on the beginning of a move
void Board::removeHopped(bool isWhite) {
	if (isWhite) {
		for (int i = 0; i < 8; ++i) {
			if (m_pawnW[i].m_hasHopped) {
				m_pawnW[i].m_hasHopped = false;
				return;
			}
		}
	}
	else{
		for (int i = 0; i < 8; ++i) {
			if (m_pawnB[i].m_hasHopped) {
				m_pawnB[i].m_hasHopped = false;
				return;
			}
		}
	}
}

Pawn* Board::getPawn(bool isWhite){
	if (isWhite) {
		return m_pawnW;
	}
	else{
		return m_pawnB;
	}
}
