//Bernd Uijtdebroeks
#include "game.h"
#include <iostream>

Game::Game(const int& white) { // Creates a game based on which player has to be 
	if (white == 0) {
		Player player1{ true };
		Player player2{ false };
		m_player1 = player1;
		m_player2 = player2;
	}
	else {
		Player player1{ false };
		Player player2{ true };
		m_player1 = player1;
		m_player2 = player2;
	}
	Board board{};
	m_board = board;
	m_turn = 0;
	m_hasEnded = false;
}

void Game::checkEnd() { // Checks if end conditions have been met
	for (int i = 1; i <= 8; ++i) {
		if (m_board.checkPiece(i, 8, true) != NULL) {
			whiteVictory();
			m_hasEnded = true;
		}
		if (m_board.checkPiece(i, 1, false) != NULL) {
			blackVictory();
			m_hasEnded = true;
		}
	}
}

int Game::movePiece(const int& x1, const int& y1, const int& x2, const int& y2) { // Moves a piece from x1y1 to x2y2
	if (m_turn % 2 == 0) {
		return m_board.movePiece(x1, y1, x2, y2, true);
	}
	else {
		return m_board.movePiece(x1, y1, x2, y2, false);
	}
}

void Game::whiteVictory() { // Puts win message if white wins
	if (m_player1.isWhite()) {
		std::cout << "Player 1 won the game as White!!!\n";
	}
	else {
		std::cout << "Player 2 won the game as White!!!\n";
	}
}

void Game::blackVictory() { // Puts win message if black wins
	if (m_player1.isWhite()) {
		std::cout << "Player 2 won the game as Black!!!\n";
	}
	else {
		std::cout << "Player 1 won the game as Black!!!\n";
	}
}
