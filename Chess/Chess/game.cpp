//Bernd Uijtdebroeks
#include "game.h"
#include <iostream>

#define WHITE true
#define BLACK false

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

int Game::movePiece(const int& x1, const int& y1, const int& x2, const int& y2) { // Moves a piece from x1y1 to x2y2 (Bernd Uijtdebroeks)
	if (m_turn % 2 == 0) {
		return m_board.makeMove(x1, y1, x2, y2, WHITE);
	}
	else {
		return m_board.makeMove(x1, y1, x2, y2, BLACK);
	}
}

void Game::checkEnd() { // Checks if end conditions have been met (Bernd Uijtdebroeks)
	for (int i = 1; i <= 8; ++i) {
		if (m_board.checkPiece(i, 8, true) != NULL) {
			declareWinner(WHITE);
			declareVictory();
			m_hasEnded = true;
			return;
		}
		else if (m_board.checkPiece(i, 1, false) != NULL) {
			declareWinner(BLACK);
			declareVictory();
			m_hasEnded = true;
			return;
		}
	}
	if(!canMove(BLACK)){
		declareWinner(WHITE);
		declareVictory();
		m_hasEnded = true;
		return;
	}
	else if(!canMove(WHITE)) {
		declareWinner(BLACK);
		declareVictory();
		m_hasEnded = true;
		return;
	}
}

// Checks if the given player has a valid move (Denzell Mgbokwere)
bool Game::canMove(bool isWhite) {
	Pawn* pawns = m_board.getPawn(isWhite);
	for (int i = 0; i < 8; ++i) {
		if (!pawns[i].isTaken()) {
			for (int j = 1; j <= 8; ++j) {
				for (int k = 1; k <= 8; ++k) {
					if (m_board.checkMove(pawns[i].getX(), pawns[i].getY(), j, k, isWhite) == 0)
						return true;
				}
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

void Game::declareVictory() { // Puts win message if white wins (Bernd Uijtdebroeks)
	if (m_player1.getWon()) {
		std::cout << "#################################\n";
		std::cout << "Player 1 won the game as White!!!\n";
		std::cout << "#################################\n";
	}
	else if (m_player2.getWon()) {
		std::cout << "#################################\n";
		std::cout << "Player 2 won the game as Black!!!\n";
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

void Game::declareWinner(bool isWhite) {
	if (isWhite)
		m_player1.giveWon();
	else
		m_player2.giveWon();
}