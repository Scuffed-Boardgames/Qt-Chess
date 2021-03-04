#ifndef BOARD_H
#define BOARD_H

#include "pawn.h"
#include <array>

class Board {
public:
	Board();
	Pawn* checkEnemy(int x, int y, bool isWhite);
private:
	Pawn m_pawnW[8];
	Pawn m_pawnB[8];
};

#endif 
