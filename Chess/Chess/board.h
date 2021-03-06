//Bernd Uijtdebroeks
#ifndef BOARD_H
#define BOARD_H
#include "pawn.h"
#include "tile.h"

class Board {
public:
	Board();
	Pawn* checkPiece(int x, int y, bool isWhite);
	int checkMove(int x_1, int y_1, int x_2, int y_2, bool isWhite);
	int makeMove(int x_1, int y_1, int x_2, int y_2, bool isWhite);
	void print();
	int countWhitePawns();
	int countBlackPawns();
	void removeHopped(bool isWhite);
	Pawn* getPawn(bool isWhite);

private:
	// we only need an 8x8 matrix but now the coordinates overlap
	Tile m_tiles[9][9];
	Pawn m_pawnW[8];
	Pawn m_pawnB[8];
};

#endif 
