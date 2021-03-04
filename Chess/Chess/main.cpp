#include "game.h"
#include "ai.h"
#include <iostream>

int main() {
	Game mainGame{};
	std::cout << "Do you want to add an AI?\n(no = 0, white = 1, black = 2)\n";
	int aiCount;
	std::cin >> aiCount;
	mainGame.setAi(aiCount);
	Ai aiW{ true, mainGame.giveBoard() };
	Ai aiB{ false, mainGame.giveBoard() };
	while (mainGame.hasEnded() == false) {
		if (mainGame.isAi(mainGame.getTurn() % 2)) {
			if (mainGame.getTurn() % 2 == 0)
				aiW.playMove();
			else
				aiB.playMove();
		}
		else {
			int x1, x2, y1, y2;
			std::cout << "Player " << (mainGame.getTurn() % 2) + 1 << "\n";
			std::cout << "Enter the position of the piece you want to move: ";
			std::cin >> x1 >> y1;
			std::cout << "Enter the position of the place you want to move to: ";
			std::cin >> x2 >> y2;
			mainGame.movePiece(x1, y1, x2, y2);
		}
		mainGame.print();
		mainGame.checkEnd();
		mainGame.addTurn();
	}
	return 0;
}
