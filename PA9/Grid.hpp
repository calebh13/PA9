#pragma once
#include "SFML/Graphics.hpp"

namespace Grid
{

// Grid is nxn; this returns n
int getGridDimension(void);

// Takes a pos vector and "rounds it down" to the nearest multiple of the grid coordinates
// Makes objects nicely aligned to the grid
void snapToGrid(sf::Vector2f& pos, const sf::RenderWindow& window);

// Takes a pos vector and returns a vector that contains the indices of the cell containing that position
sf::Vector2i getGridIndices(const sf::Vector2f& pos, const sf::RenderWindow& window);

// Takes a grid vector and converts it to the coordinates of the top left pixel of that cell
sf::Vector2f getGridPos(int x, int y, const sf::RenderWindow& window);

};