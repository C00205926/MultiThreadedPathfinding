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
	void render(sf::RenderWindow* win);

private:
	int height = 100, width = 100;

	Tile* grid[100][100];
};

