//Bernd Uijtdebroeks
#ifndef BOARD_H
#define BOARD_H

#include "pawn.h"
#include <array>

class Board {
public:
	Board();
	Pawn* checkPiece(int x, int y, bool isWhite);
	int movePiece(int x_1, int y_1, int x_2, int y_2, bool isWhite);
	Pawn* getPawnW();
	Pawn* getPawnB();
	void print();
private:
	Pawn m_pawnW[8];
	Pawn m_pawnB[8];
};

#endif 
