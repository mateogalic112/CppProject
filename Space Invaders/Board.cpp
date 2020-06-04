
#include "Board.h"

// Create Board
char** Board::make_board() {
	
	// Allocating memory
	char** newGameBoard = new char*[width];
	for (int i = 0; i < width; ++i) {
		newGameBoard[i] = new char[height];
	}

	// Initial Board Setup
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (i == 0 || i == height - 1) {
				newGameBoard[j][i] = border;
			}
			else if (j == 0 || j == width - 1) {
				newGameBoard[j][i] = border;
			}
			else {
				newGameBoard[j][i] = ' ';
			}
		}
	}

	return newGameBoard;
}

Board::Board() {
	gameBoard = make_board();
}

Board::~Board() {
	for (int i = 0; i < width; ++i) 
		delete gameBoard[i];
	delete gameBoard;
}

void Board::printBoard() const {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << gameBoard[j][i];
		}
		std::cout << std::endl;
	}
}

void Board::draw_char(Position p, char c) {
	gameBoard[p.getY()][p.getX()] = c;
}

