#include "Grid.hpp"
#include "iostream"
constexpr int GRID_DIMENSION = 24;

int Grid::getGridDimension(void)
{
	return GRID_DIMENSION;
}

sf::Vector2f Grid::snapToGrid(const sf::Vector2f& pos, const sf::RenderWindow& window)
{
	// grid is 32x32, so each cell is the window size / 32
	// also, window will always be square, so x == y
	float cellSize = (float)window.getSize().x / GRID_DIMENSION;
	return sf::Vector2f(pos.x - fmodf(pos.x, cellSize), pos.y - fmodf(pos.y, cellSize));
}

sf::Vector2f Grid::snapToGrid(const sf::Vector2f& pos, const float objScale)
{
	float cellSize = objScale * 16;
	return sf::Vector2f(pos.x - fmodf(pos.x, cellSize), pos.y - fmodf(pos.y, cellSize));
}

sf::Vector2i Grid::getGridIndices(const sf::Vector2f& pos, const sf::RenderWindow& window)
{
	float cellSize = (float)window.getSize().x / GRID_DIMENSION;
	return sf::Vector2i((int)floor(pos.x / cellSize), (int)floor(pos.y / cellSize));
}

sf::Vector2i Grid::getGridIndices(const sf::Vector2f& pos, const float objScale)
{
	// objScale = (float)windowDimension / (16 * Grid::getGridDimension());
	// objScale * 16 * Grid::getGridDimension() = windowDimension
	// gridDimension cancels out, so:
	float cellSize = (objScale * 16);
	return sf::Vector2i((int)floor(pos.x / cellSize), (int)floor(pos.y / cellSize));
}

sf::Vector2f Grid::getGridPos(int x, int y, const sf::RenderWindow& window)
{
	float cellSize = (float)window.getSize().x / GRID_DIMENSION;
	return sf::Vector2f((float)x * cellSize, (float)y * cellSize);
}

sf::Vector2f Grid::getGridPos(int x, int y, const float objScale)
{
	float cellSize = (objScale * 16);
	return sf::Vector2f((float)x * cellSize, (float)y * cellSize);
}
