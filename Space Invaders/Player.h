#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Position.h"
#include "Bullet.h"
#include "Board.h"

#include <iostream>

class Player {
	Position position;
	int score;
public:
	// Player Char
	static const char playerChar = 'W';
	// Player Bullet
	static const char playerBullet = '^';

	// Constructor
	Player() : position(18, 20), score(0) {};

	// Get Position
	Position getPosition() const { return position; }
	// GetScore
	int getScore() const { return score; }

	// Set Position - Only Vertical
	void setPosition(int y) { this->position.setY(y); }
	// Set Score
	void setScore() { score++; }

};

#endif // !PLAYER_H
