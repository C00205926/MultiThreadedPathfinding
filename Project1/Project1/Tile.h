#pragma once
#include "SFML/Graphics.hpp"
class Tile
{
public:
	Tile(sf::Vector2f pos);
	~Tile();

	void update();
	void render(sf::RenderWindow* win);

	sf::RectangleShape m_tile;

	int height = 15;
	int width = 15;
};

