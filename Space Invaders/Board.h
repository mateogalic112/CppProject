#pragma once
#ifndef BOARD_H
#define BOARD_H

#include "Player.h"

#include <iostream>

class Board {
private:
	char** gameBoard;
	// Alocate Board - private function
	char** make_board();

public:
	// Public Property Members
	static const int width = 40, height = 20;
	static const char border = 'O';
	Board();
	~Board();

	// Get Board
	char** getBoard() const { return gameBoard; };

	// Print Board
	void printBoard() const;

	// Draw Objects on Board
	void draw_char(Position, char);

};

#endif // !BOARD_H
