#include "game.h"

Game::Game() : m_window(sf::VideoMode(500, 500), "GamesEng")
{

}

void Game::run()
{
	while (m_window.isOpen()) {
		update();
		while (m_window.pollEvent(ev))
		{

		}
		render();
	}
}

void Game::update()
{

}

void Game::render()
{
	g.render(&m_window);
}