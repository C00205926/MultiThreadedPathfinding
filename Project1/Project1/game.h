#pragma once
#include "SFML/Graphics.hpp"
#include "grid.h"
#include <iostream>

class Game
{
public:

	Game();
	~Game();

	void run();
	void update();
	void render();

	sf::RenderWindow m_window;

	sf::Mouse mouse;

	sf::Keyboard k;

	int clickX = 30 ,clickY = 20;

private:
	sf::Event ev;

	sf::Vector2f m_mousePos;

	Grid grid;
};

