//Bernd Uijtdebroeks
#include "game.h"
#include <iostream>

Game::Game() { // Creates a game based on which player has to be 
	Player player1{ true };
	Player player2{ false };
	m_player1 = player1;
	m_player2 = player2;
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

void Game::addTurn() {
	m_turn += 1;
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

void Game::print() {
	m_board.print();
}

