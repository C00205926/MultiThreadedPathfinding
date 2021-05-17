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
			grid[x][y] = new Tile(sf::Vector2f(sizeX * x, sizeY * y), &t_font);
		}
	}
}

Grid::~Grid()
{

}

void Grid::gridFifty()
{
	height = 50;
	width = 50;

	*grid[50][50];
}

void Grid::gridHundred()
{
	height = 100;
	width = 100;

	*grid[100][100];
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
	if (start_b && end_b)
	{
		SetStartCost();
	}

}

void Grid::obs(sf::Vector2f m_pos) 
{
	
	if (grid[(int)m_pos.x][(int)m_pos.y]->obstacle != true && grid[(int)m_pos.x][(int)m_pos.y]->start != true, grid[(int)m_pos.x][(int)m_pos.y]->end != true)
	{
		grid[(int)m_pos.x][(int)m_pos.y]->obstacle = true;
		grid[(int)m_pos.x][(int)m_pos.y]->SetCost(999);
		grid[(int)m_pos.x][(int)m_pos.y]->text.setFillColor(sf::Color::White);
	}

}

void Grid::start(sf::Vector2f m_pos) 
{
	if (start_b != true && grid[(int)m_pos.x][(int)m_pos.y]->end != true && grid[(int)m_pos.x][(int)m_pos.y]->obstacle != true) 
	{
		start_b = true;
		grid[(int)m_pos.x][(int)m_pos.y]->start = true;
	}
}

void Grid::end(sf::Vector2f m_pos)
{
	if (end_b != true && grid[(int)m_pos.x][(int)m_pos.y]->start != true && grid[(int)m_pos.x][(int)m_pos.y]->obstacle  != true) 
	{
		end_b = true;
		grid[(int)m_pos.x][(int)m_pos.y]->end = true;
	}
}

void Grid::SetStartCost()
{
	Tile* s_tile = new Tile(sf::Vector2f(0, 0), &t_font);
	int tileX;
	int tileY;

	for (int x = 0; x < height; x++)
	{
		for (int y = 0; y < width; y++)
		{
			if (grid[x][y]->start)
			{
				s_tile = grid[x][y];
				p_Que.push_back(s_tile);
				tileX = x;
				tileY = y;
			}
		}
	}

	grid[tileX][tileY]->SetCost(0);
	p_Que.push_back(s_tile);
	//int cost = 0;

	for (int x = 0; x < 50; x++)
	{
		SetUpCost(tileX, tileY);
	}

}

void Grid::SetUpCost(int x, int y)
{
	int cost_up = 1;
	int cost_down = 1;
	int cost_right = 1;
	int cost_left = 1;

	int cost_botR = 1;
	int cost_botL = 1;
	int cost_TopL = 1;
	int cost_TopR = 1;

	if (y < 49 && grid[x][y + 1]->start != true && grid[x][y + 1]->obstacle != true && grid[x][y + 1]->done != true)
	{

		setUpNode(x, y, 0, 1, cost_up);
		cost_up = cost_up + 1;

	}
	if (y > 0 && grid[x][y - 1]->start != true && grid[x][y - 1]->obstacle != true && grid[x][y - 1]->done != true)
	{
		setUpNode(x, y, 0, -1, cost_down);
		cost_down = cost_down + 1;
	}

	if (x < 49 && grid[x + 1][y]->start != true && grid[x + 1][y]->obstacle != true && grid[x + 1][y]->done != true)
	{
		setUpNode(x, y, 1, 0, cost_right);
		cost_right = cost_right + 1;
	}
	if (x > 0 && grid[x - 1][y]->start != true && grid[x - 1][y]->obstacle != true && grid[x - 1][y]->done != true)
	{
		setUpNode(x, y, -1, 0, cost_left);
		cost_left = cost_left + 1;
	}

	if (x < 49 && y < 49 && grid[x + 1][y + 1]->start != true && grid[x + 1][y + 1]->obstacle != true && grid[x + 1][y + 1]->done != true)
	{
		setUpNode(x, y, 1, 1, cost_botR);
		cost_botR = cost_botR + 1;
	}
	if (x > 0 && y < 49  && grid[x - 1][y + 1]->start != true && grid[x - 1][y + 1]->obstacle != true && grid[x - 1][y + 1]->done != true)
	{
		setUpNode(x, y, -1, 1, cost_botL);
		cost_botL = cost_botL + 1;
	}

	if (x > 0 && y > 0 && grid[x - 1][y - 1]->start != true && grid[x - 1][y - 1]->obstacle != true && grid[x - 1][y - 1]->done != true)
	{
		setUpNode(x, y, -1, -1, cost_TopL);
		cost_TopL = cost_TopL + 1;
	}
	if (x < 49 && y > 0 && grid[x + 1][y - 1]->start != true && grid[x + 1][y - 1]->obstacle != true && grid[x + 1][y - 1]->done != true)
	{
		setUpNode(x, y, 1, -1, cost_TopR);
		cost_TopR = cost_TopR + 1;
	}

}


void Grid::setUpNode(int row, int col, int n_row, int n_col, int cost)
{
	int nextRow, nextCol;

	nextRow = row + n_row;
	nextCol = col + n_col;

	grid[nextRow][nextCol]->SetCost(cost);
	grid[nextRow][nextCol]->done = true;
	grid[nextRow][nextCol]->p_node = std::make_pair(row, col);
	p_Que.push_back(grid[nextRow][nextCol]);
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