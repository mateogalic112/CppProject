#pragma once
#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include "Enemy.h"

#include "vector"

class Game {
public:
	static void startGame(Board&, Player&, std::vector<Enemy>&);
};

#endif // !GAME_H

