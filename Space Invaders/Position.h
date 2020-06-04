#pragma once
#ifndef POSITION_H
#define POSITION_H

class Position {
	int x, y;
public:
	Position(int x, int y) {
		this->x = x;
		this->y = y;
	}

	int getX() { return x; }
	int getY() const { return y; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

};

#endif // !POSITION_H
