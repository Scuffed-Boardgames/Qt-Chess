#include "pawn.h"
int main() {
	Position pos{ 2,1 };
	Pawn pawn(pos, true);
	Position dest_1{ 2,2 };
	pawn.move(dest_1);
	Position dest_2{ 2,4 };
	pawn.move(dest_2);
	return 0;
}