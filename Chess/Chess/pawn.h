//Denzell Mgbokwere
#ifndef PAWN_H
#define PAWN_H



class Pawn{
public:
	Pawn() = default;
	Pawn(int x, int y, bool isWhite);

	int checkMove(int x, int y);
	int checkTake(int x, int y);
	int makeMove(int x, int y);
	int makeTake(int x, int y);

	void setTaken();
	void toTheShadowRealm();

	int getX();
	int getY();
	bool isTaken();
	bool hasMoved();
	bool isWhite();

	bool m_hasHopped;

private:
	bool checkBounds(int x, int y);

	int m_x;
	int m_y;
	bool m_isWhite;
	bool m_hasMoved;
	bool m_isTaken;
};
#endif 
