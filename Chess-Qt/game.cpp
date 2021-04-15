//Bernd Uijtdebroeks
#include "game.h"
#include "ai.h"
#include <iostream>
#include <time.h>


Game::Game() : m_player1(Colour::white), m_player2(Colour::white), m_board(), m_turn(0), m_hasEnded(false)
{}

error Game::movePiece(const int& x1, const int& y1, const int& x2, const int& y2) {
	if (m_turn % 2 == 0) {
        return m_board.makeMove(x1, y1, x2, y2, Colour::white);
	}
	else {
        return m_board.makeMove(x1, y1, x2, y2, Colour::black);
	}
}

void Game::checkEnd() {
    for (int i = 0; i <= 7; ++i) {
		if (m_board.getPieces(Colour::black).size() < m_minPieces) {
			declareVictory(Colour::white);
			return;
		}
		else if (m_board.getPieces(Colour::white).size() < m_minPieces) {
			declareVictory(Colour::black);
			return;
		}
	}
	if(!canMove(Colour::black)){
		declareVictory(Colour::white);
		return;
	}
	else if(!canMove(Colour::white)) {
		declareVictory(Colour::black);
		return;
	}
}

bool Game::canMove(Colour colour) {
	std::vector<Piece*> pieces = m_board.getPieces(colour);
	size_t len = pieces.size();
    for (size_t i = 0; i < len; ++i) {
        for (int j = 0; j <= 7; ++j) {
            for (int k = 0; k <= 7; ++k) {
                if ((int)m_board.checkMove(pieces[i]->getX(), pieces[i]->getY(), j, k, colour) == 0)
					return true;
			}
		}
	}
	return false;
}

void Game::addTurn() {
	m_turn += 1;
}

void Game::print() {
	m_board.print();
}

void Game::declareVictory(Colour colour) {
	m_hasEnded = true;
	if (colour == Colour::white) {
		std::cout << "#################################\n";
		std::cout << "Player 1 won the game as White!!!\n";
		std::cout << "#################################\n";
	}
	else if (colour == Colour::black) {
		std::cout << "#################################\n";
		std::cout << "Player 2 won the game as Black!!!\n";
		std::cout << "#################################\n";
	}
	else {
		std::cout << "#################################\n";
		std::cout << "Player 0 won the game as None?!?!\n";
		std::cout << "#################################\n";
	}
}

bool Game::hasEnded() {
	return m_hasEnded;
}

void Game::setAi(int aiCount) {
	if (aiCount == 1)
		m_player1.setAi();
	else if (aiCount == 2)
		m_player2.setAi();
	else if (aiCount == 3) {
		m_player1.setAi();
		m_player2.setAi();
	}
}


Board* Game::giveBoard() {
	return &m_board;
}

bool Game::isAi(int player) {
	if (player == 0)
		return m_player1.isAi();
	else
		return m_player2.isAi();
}

int Game::getTurn() {
	return m_turn;
}

int Game::play() {
	srand((unsigned)time(NULL));
	std::cout << "Do you want to add an AI?\n(no = 0, white = 1, black = 2)\n";
	int aiCount = 3;
	std::cin >> aiCount;
	setAi(aiCount);
	Ai aiW(Colour::white, giveBoard());
	Ai aiB(Colour::black, giveBoard());
	print();
	while (hasEnded() == false) {
		if (isAi(getTurn() % 2)) {
			int test = 1;
			while (test != 0) {
				if (getTurn() % 2 == 0)
					test = aiW.playMove();
				else
					test = aiB.playMove();
			}
		}
		else {
			int test = 1;
			while (test != 0) {
				int x1, x2, y1, y2;
				std::cout << "Player " << (getTurn() % 2) + 1 << "\n";
				std::cout << "Enter the position of the piece you want to move: \n";
				std::cin >> x1 >> y1;
				std::cout << "Enter the position of the place you want to move to: \n";
				std::cin >> x2 >> y2;
                test = (int)movePiece(x1, y1, x2, y2);
			}
		}
		print();
		checkEnd();
		addTurn();
	}
	return 0;
}

void Game::resetBoard(){
    m_board.resetBoard();
}
