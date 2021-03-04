#ifndef POSITION_H
#define POSITION_H

class Position {
public:
	void move(const Position &dest);
	Position(int x, int y);
private:
	int m_x;
	int m_y;
};
#endif
