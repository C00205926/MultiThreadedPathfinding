#pragma once

#include "SFML/Graphics.hpp"
#include "tile.h"
#include <vector>

class Grid
{
public:
	Grid();
	~Grid();

	void gridFifty();
	void gridHundred();
	void Clear();


	void update();
	void render(sf::RenderWindow * win);

	void obs(sf::Vector2f m_pos);

	void start(sf::Vector2f m_pos);

	void end(sf::Vector2f m_pos);

	void SetStartCost();
	void SetUpCost(int x, int y);


	void setUpNode(int row, int col, int n_row, int n_col, int cost);

	bool start_b = false;
	bool end_b = false;

	sf::Font t_font;


private:
	int sizeX = 30, sizeY = 20;

	int height = 50, width = 50;

	Tile *grid[50][50];

	std::vector<Tile *> p_Que;

	bool cost_b = true;
};

