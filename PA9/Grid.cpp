#include "Grid.hpp"

void Grid::snapToGrid(sf::Vector2f& pos, const sf::RenderWindow& window)
{
	// grid is 32x32, so each cell is the window size / 32
	// also, window will always be square, so x == y
	float cellSize = (float)window.getSize().x / 32;
	pos.x -= fmodf(pos.x, cellSize);
	pos.y -= fmodf(pos.y, cellSize);
}

sf::Vector2i Grid::getGridIndices(const sf::Vector2f& pos, const sf::RenderWindow& window)
{
	float cellSize = (float)window.getSize().x / 32;
	return sf::Vector2i((int)floor(pos.x / cellSize), (int)floor(pos.y / cellSize));
}

sf::Vector2f Grid::getGridPos(const sf::Vector2i& indices, const sf::RenderWindow& window)
{
	float cellSize = (float)window.getSize().x / 32;
	return sf::Vector2f(indices.x * cellSize, indices.y * cellSize);
}