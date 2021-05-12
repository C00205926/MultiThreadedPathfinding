#pragma once

#include "SFML/Graphics.hpp"
#include "tile.h"
#include <vector>

class Grid
{
public:
	Grid();
	~Grid();

	void update();
	void render(sf::RenderWindow * win);

	void obs(sf::Vector2f m_pos);

	void start(sf::Vector2f m_pos);

	void end(sf::Vector2f m_pos);

	bool start_b = false;
	bool end_b = false;

private:
	int height = 50, width = 50;

	Tile *grid[50][50];
};

