#ifndef PAWN_H
#define PAWN_H

#include "position.h"

class Pawn{
public:
	Pawn(Position position, bool isWhite);
	int move(Position destination);
	int take(Position target);


private:
	bool m_isWhite;
	bool m_hasMoved;
	bool m_isTaken;
	Position m_position{ 0,0 };
};
#endif 
