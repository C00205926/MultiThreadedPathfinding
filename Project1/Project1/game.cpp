#include "game.h"

Game::Game() : m_window(sf::VideoMode(750, 750), "GamesEng")
{
}

void Game::run()
{
	while (m_window.isOpen()) {
		update();
		while (m_window.pollEvent(ev))
		{

		}
		m_mousePos.x = mouse.getPosition(m_window).x / 15;
		m_mousePos.y = mouse.getPosition(m_window).y / 15;
		if (mouse.isButtonPressed(sf::Mouse::Left)) 
		{
			if (m_mousePos.x < 50) {
				grid.obs(m_mousePos);
			}
		}
		if (mouse.isButtonPressed(sf::Mouse::Middle))
		{
			if (m_mousePos.x < 50) {
				grid.start(m_mousePos);
			}
		}
		if (mouse.isButtonPressed(sf::Mouse::Right))
		{
			if (m_mousePos.x < 50) {
				grid.end(m_mousePos);
			}
		}
		render();
	}
}

void Game::update()
{
	grid.update();

	//std::cout << "x:" << m_mousePos.x << "y: " << m_mousePos.y << std::endl;
}

void Game::render()
{
	m_window.clear();

	grid.render(&m_window);

	m_window.display();
}