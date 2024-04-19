#include "SFML/Graphics.hpp"

namespace Grid
{

// Takes a pos vector and "rounds it down" to the nearest multiple of the grid coordinates
// Makes objects nicely aligned to the grid
void snapToGrid(sf::Vector2f& pos, const sf::RenderWindow& window)
{
	// grid is 32x32, so each cell is the window size / 32
	// also, window will always be square, so x == y
	float cellSize = (float)window.getSize().x / 32;
	pos.x -= fmodf(pos.x, cellSize);
	pos.y -= fmodf(pos.y, cellSize);
}

// Takes a pos vector and returns a vector that contains the indices of the cell containing that position
sf::Vector2i getGridIndices(const sf::Vector2f& pos, const sf::RenderWindow& window)
{
	float cellSize = (float)window.getSize().x / 32;
	return sf::Vector2i((int)floor(pos.x / cellSize), (int)floor(pos.y / cellSize));
}

// Takes a grid vector and converts it to the coordinates of the top left pixel of that cell
sf::Vector2f getGridPos(const sf::Vector2i& gridIndices, const sf::RenderWindow& window)
{
	float cellSize = (float)window.getSize().x / 32;
	return sf::Vector2f(gridIndices.x * cellSize, gridIndices.y * cellSize);
}
};