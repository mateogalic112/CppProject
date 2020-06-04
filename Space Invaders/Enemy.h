#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Position.h"
#include "windows.h"

class Enemy {
	Position p;
	char enemyChar;
public:
	// Overload Constructor
	Enemy(int x, int y) : p(x, y), enemyChar('Y') {};

	// Get Position & Char
	Position getPosition() const { return p; };
	char getChar() const { return enemyChar; };

	// Set Position & Char
	void setPosition(int x, int y) { this->p.setX(x); this->p.setY(y); }
	void setChar() { enemyChar = ' '; }

	//Move Down After Player Shoots
	void moveDown() { 
		p.setX(p.getX() + 1); 
	}



};

#endif // !ENEMY_H
