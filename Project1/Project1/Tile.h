#pragma once
#include "SFML/Graphics.hpp"
#include <string>
class Tile
{
public:
	Tile(sf::Vector2f pos, sf::Font *font);
	~Tile();

	void update();
	void render(sf::RenderWindow* win);

	void SetCost(int cost);

	sf::RectangleShape m_tile;
	sf::Text text;

	int height = 30;
	int width = 30;
	int t_cost = 0;

	
	bool obstacle = false;
	bool end = false;
	bool start = false;
	bool done = false;

	std::pair<int, int> p_node;
};

