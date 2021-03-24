#pragma once
#include "SFML/Graphics.hpp"
#include "grid.h"

class Game
{
public:

	Game();
	~Game();

	void run();
	void update();
	void render();

	sf::RenderWindow m_window;

private:
	sf::Event ev;

	Grid g;
};

