#include "game.h"

Game::Game() : m_window(sf::VideoMode(1500, 1000), "GamesEng")
{
}

void Game::run()
{
	while (m_window.isOpen()) {
		update();
		while (m_window.pollEvent(ev))
		{

		}
		if (k.isKeyPressed(sf::Keyboard::Num1))
		{
			grid.gridFifty();

			clickX = 30;
			clickY = 20;
		}

		if (k.isKeyPressed(sf::Keyboard::Num2))
		{
			grid.gridHundred();

			clickX = 15;
			clickY = 10;
		}
		m_mousePos.x = mouse.getPosition(m_window).x / clickX;
		m_mousePos.y = mouse.getPosition(m_window).y / clickY;
		if (mouse.isButtonPressed(sf::Mouse::Left)) 
		{
			if (m_mousePos.x < 1000) {
				grid.obs(m_mousePos);
			}
		}
		if (mouse.isButtonPressed(sf::Mouse::Middle))
		{
			if (m_mousePos.x < 1000) {
				grid.start(m_mousePos);
			}
		}
		if (mouse.isButtonPressed(sf::Mouse::Right))
		{
			if (m_mousePos.x < 1000) {
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
	m_window.clear(sf::Color(45, 45, 45, 255));

	grid.render(&m_window);

	m_window.display();
}