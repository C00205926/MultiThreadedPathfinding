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

	int height = 30;
	int width = 30;
	
	bool obstacle = false;
	bool end = false;
	bool start = false;
};

