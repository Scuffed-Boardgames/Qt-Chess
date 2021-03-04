#ifndef AI_H
#define AI_H

#include "board.h"

class Ai{
public:
	Ai(bool isWhite, Board* board);
	int playMove();
private:
	bool checkTake();
	bool m_isWhite;
	Board* m_board;
	int movePiece();
};


#endif 

