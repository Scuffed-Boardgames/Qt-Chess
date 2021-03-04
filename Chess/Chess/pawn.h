//Denzell Mgbokwere
#ifndef PAWN_H
#define PAWN_H



class Pawn{
public:
	Pawn() = default;
	Pawn(int x, int y, bool isWhite);

	int move(int x, int y);
	int validTake(int x, int y);

	void setTaken();
	void toTheShadowRealm();

	int getX();
	int getY();
	bool getColour();
	bool getStatus();
	bool hasMoved();
private:
	bool checkBounds(int x, int y);

	bool m_isWhite;
	bool m_hasMoved;
	bool m_isTaken;
	int m_x;
	int m_y;
};
#endif 
