#include "Tile.h"
#include <iostream>
Tile::Tile(sf::Vector2f pos, sf::Font *font)
{

	m_tile.setSize(sf::Vector2f(height, width));
	m_tile.setFillColor(sf::Color::Blue);
	m_tile.setOutlineColor(sf::Color::Black);
	m_tile.setOutlineThickness(1.0f);
	m_tile.setPosition(pos);

	text.setFont(*font);
	text.setPosition(pos);
	text.setCharacterSize(10.0f);
	text.setFillColor(sf::Color::Black);
	text.setString(std::to_string(t_cost));
}

void Tile::SetCost(int cost)
{
	t_cost = cost;
}

Tile::~Tile()
{

}

void Tile::render(sf::RenderWindow* window)
{
	window->draw(m_tile);
	window->draw(text);
}

void Tile::update()
{
	if (obstacle) {
		m_tile.setFillColor(sf::Color::Black);
	}
	if (start) {
		m_tile.setFillColor(sf::Color::Green);
	}
	if (end) {
		m_tile.setFillColor(sf::Color::Red);
	}
}