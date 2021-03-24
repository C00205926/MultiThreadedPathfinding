#include "Tile.h"

Tile::Tile(sf::Vector2f pos)
{
	m_tile.setSize(sf::Vector2f(height, width));
	m_tile.setFillColor(sf::Color::Blue);
	m_tile.setOutlineColor(sf::Color::Black);
	m_tile.setOutlineThickness(1.0f);
	m_tile.setPosition(pos);
}

Tile::~Tile()
{

}

void Tile::render(sf::RenderWindow* window)
{
	window->draw(m_tile);
}

void Tile::update()
{

}