
#include <iostream>

#include "Board.h"
#include "Position.h"
#include "Player.h"
#include "Game.h"
#include "Enemy.h"
#include "vector"
#include <time.h>     

int main()
{
    srand(time(0));
    Board board;
    Player p;

    std::vector<Enemy> enemies;

    for (int i = 1; i < 11; i++) {
        Enemy e(i, (rand() % 39) + 1);
        enemies.push_back(e);
    }
    Game::startGame(board, p, enemies);

}
