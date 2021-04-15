//Bernd Uijtdebroeks
#include "game.h"
#include "ai.h"
#include <iostream>
#include <time.h>


Game::Game() : m_player1(Colour::white), m_player2(Colour::black), m_board(new Board()), m_ai(new Ai(m_board)), m_turn(0), m_hasEnded(false)
{}

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


std::shared_ptr<Board> Game::giveBoard() {
    return m_board;
}

bool Game::isAi(int player) {
	if (player == 0)
        return m_player1.isAi();
	else
        return m_player2.isAi();
}

void Game::resetBoard(){
    m_board->resetBoard();
}

std::shared_ptr<Ai> Game::giveAi() {
    return m_ai;
}
