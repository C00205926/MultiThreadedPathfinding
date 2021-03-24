#include "grid.h"

Grid::Grid()
{
	for (int x = 0; x < height; x++) 
	{
		for (int y = 0; y < width; y++)
		{
			grid[x][y] = new Tile(sf::Vector2f(15 * x, 15 * y));
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
		for (int y = 0; y < width; x++)
		{
			grid[x][y]->update();
		}
	}
}

void Grid::render(sf::RenderWindow* win)
{
	for (int x = 0; x < height; x++)
	{
		for (int y = 0; y < width; x++)
		{
			grid[x][y]->render(win);
		}
	}
}