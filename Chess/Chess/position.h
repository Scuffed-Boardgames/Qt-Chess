#ifndef POSITION_H
#define POSITION_H

class Position {
public:
	void move(const Position &dest);
	Position(int x, int y);

	int m_x;
	int m_y;

private:

};
#endif
