#include "grid.h"
#include <iostream>

Grid::Grid()
{
	if (!t_font.loadFromFile("arial.ttf"))
	{
		std::cout << "Error Loading Font" << std::endl;
	}

	for (int x = 0; x < height; x++) 
	{
		for (int y = 0; y < width; y++)
		{
			grid[x][y] = new Tile(sf::Vector2f(15 * x, 15 * y), &t_font);
		}
	}
}

Grid::~Grid()
{

}

void Grid::update()
{
	for (int x = 0; x < height; x++)
	{
		for (int y = 0; y < width; y++)
		{
			grid[x][y]->update();
		}
	}
}

void Grid::obs(sf::Vector2f m_pos) 
{
	
	if (grid[(int)m_pos.x][(int)m_pos.y]->obstacle == false) {
		grid[(int)m_pos.x][(int)m_pos.y]->obstacle = true;
		grid[(int)m_pos.x][(int)m_pos.y]->text.setString(std::to_string(grid[(int)m_pos.x][(int)m_pos.y]->t_cost = 999));
		grid[(int)m_pos.x][(int)m_pos.y]->text.setFillColor(sf::Color::White);
	}

}

void Grid::start(sf::Vector2f m_pos) 
{
	if (!start_b && !grid[(int)m_pos.x][(int)m_pos.y]->end &&
		!grid[(int)m_pos.x][(int)m_pos.y]->obstacle) {
		start_b = true;
		grid[(int)m_pos.x][(int)m_pos.y]->start = true;
	}
}

void Grid::end(sf::Vector2f m_pos)
{
	if (!end_b && !grid[(int)m_pos.x][(int)m_pos.y]->start &&
		!grid[(int)m_pos.x][(int)m_pos.y]->obstacle) {
		end_b = true;
		grid[(int)m_pos.x][(int)m_pos.y]->end = true;
	}
}



void Grid::render(sf::RenderWindow* win)
{
	for (int x = 0; x < height; x++)
	{
		for (int y = 0; y < width; y++)
		{
			grid[x][y]->render(win);
		}
	}
}