 
#include "Game.h"
#include "windows.h"

void Game::startGame(Board& b, Player& p, std::vector<Enemy>& e) {

	int vectorSize = e.size();
	while (true) {
		system("cls");

		// Crtanje neprijatelja na plocu
		for (int i = 0; i < vectorSize; i++) {
			b.draw_char(e[i].getPosition(), e[i].getChar());
		}

		// Crtanje Igraca i same ploce
		b.draw_char(p.getPosition(), p.playerChar);
		b.printBoard();

		// Ispis trenutnog rezultata
		std::cout << "\nScore: " << p.getScore() << " / " << vectorSize << std::endl;

		// Pritisnuta lijeva tipka na tipkovnici - Igrac ide u lijevo do kraja ploce
		if (GetAsyncKeyState(VK_LEFT)) {
			if (b.getBoard()[p.getPosition().getY() - 1][p.getPosition().getX()] != 'O') {
				b.draw_char(p.getPosition(), ' ');
				p.setPosition(p.getPosition().getY() - 1);
				b.draw_char(p.getPosition(), p.playerChar);
			}
		}

		// Pritisnuta desna tipka na tipkovnici - Igrac ide u desno do kraja ploce
		if (GetAsyncKeyState(VK_RIGHT)) {
			if (b.getBoard()[p.getPosition().getY() + 1][p.getPosition().getX()] != 'O') {
				b.draw_char(p.getPosition(), ' ');
				p.setPosition(p.getPosition().getY() + 1);
				b.draw_char(p.getPosition(), p.playerChar);
			}
		}

		// Pritisnuta space tipka na tipkovnici - Igrac ispaljuje metak do kraja ploce ili neprijatelja
		if (GetAsyncKeyState(VK_SPACE)) {

			// Inicijalna pozicija metka
			int bulletHeight = p.getPosition().getX(); 
			int bulletWidth = p.getPosition().getY(); 

			// Petlja dok metak ne pogodi metu ili kraj ploce
			while (b.getBoard()[bulletWidth][bulletHeight-1] != 'O') {

				// Ako je pogodio neprijatelja
				if (b.getBoard()[bulletWidth][bulletHeight-1] == 'Y') {

					// Uvecaj score
					p.setScore();

					// Provjera kraja igrice i ispis pobjede
					if (vectorSize == p.getScore()) {
						std::cout << "Victory!";
						return;
					}

					// "Brisanje" pogodenog neprijatelja sa ploce
					for (int i = 0; i < vectorSize; i++) {
						if ((e.at(i).getPosition().getY() == bulletWidth)
							&& (e.at(i).getPosition().getX() == bulletHeight-1)) {
							e.at(i).setChar();
						}
					}
					break;
				}

				// Metak jos putuje
				Position pos = Position(bulletHeight-1, bulletWidth);
				b.draw_char(pos, p.playerBullet);
				pos = Position(bulletHeight, bulletWidth);
				b.draw_char(pos, ' ');
				system("cls");
				b.draw_char(p.getPosition(), p.playerChar);
				b.printBoard();
				bulletHeight--;
			}

			// Metak je došao do cilja te ga treba izbrisati s ploce
			Position pos = Position(bulletHeight, bulletWidth);
			b.draw_char(pos, ' ');

			// Pomicanje svih prezivjelih neprijatelja za jedan korak prema igracu na ploci
			for (int i = 0; i < vectorSize; i++) {
 				if (e[i].getChar() != ' ') {
					Position deletePrev = e[i].getPosition();
					e[i].moveDown();
					b.draw_char(deletePrev, ' ');

					// Ako je neprijatelj došao do visine igrača - Game Over :(
					if (e[i].getPosition().getX() == p.getPosition().getX()) {
						std::cout << "Game Over!";
						return;
					}
				}
			}
		}
		
	}
}