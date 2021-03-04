#include "pawn.h"
int main() {
	Position pos{ 2,1 };
	Pawn pawn(pos, true);
	Position dest{ 6,9 };
	pawn.move(dest);
	return 0;
}