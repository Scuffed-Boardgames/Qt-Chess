#include "game.h"
#include "ai.h"
#include <iostream>

int main() {
	srand((unsigned)time(NULL));
	Game mainGame{};
	std::cout << "Do you want to add an AI?\n(no = 0, white = 1, black = 2)\n";
	int aiCount;
	std::cin >> aiCount;
	mainGame.setAi(aiCount);
	Ai aiW{ true, mainGame.giveBoard() };
	Ai aiB{ false, mainGame.giveBoard() };
	mainGame.print();
	while (mainGame.hasEnded() == false) {
		if (mainGame.isAi(mainGame.getTurn() % 2)) {
			if (mainGame.getTurn() % 2 == 0)
				aiW.playMove();
			else
				aiB.playMove();
		}
		else {
			int test = 1;
			while (test != 0){
			int x1, x2, y1, y2;
			std::cout << "Player " << (mainGame.getTurn() % 2) + 1 << "\n";
			std::cout << "Enter the position of the piece you want to move: \n";
			std::cin >> x1 >> y1;
			std::cout << "Enter the position of the place you want to move to: \n";
			std::cin >> x2 >> y2;
			test = mainGame.movePiece(x1, y1, x2, y2);
			}
		}
		mainGame.print();
		mainGame.checkEnd();
		mainGame.addTurn();
	}
	return 0;
}
