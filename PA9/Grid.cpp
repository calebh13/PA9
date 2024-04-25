/*
	Caleb
	4/23/24

	Description: This is a header file that defines the Grid class. It is the positioning
					system for the game

// History: 4/22/24 - Class was created and implimented initially by Caleb


*/
#include "Grid.hpp"
#include "iostream"
constexpr int GRID_DIMENSION = 24;

/*************************************************************
* Function: getGridDimension()								*
* Description: Returns the size of the grid					*
* Input parameters: None									*
* Returns: Grid Size									    *
* Preconditions: None								        *
* Postconditions: None									    *
*************************************************************/
int Grid::getGridDimension(void)
{
	return GRID_DIMENSION;
}

/*************************************************************
* Function: snapToGrid()									*
* Description: Returns grid coordinates for vector coords	*
* Input parameters: Vector coords							*
* Returns: Grid coords									    *
* Preconditions: None								        *
* Postconditions: None									    *
*************************************************************/
sf::Vector2f Grid::snapToGrid(const sf::Vector2f& pos, const sf::RenderWindow& window)
{
	// grid is 32x32, so each cell is the window size / 32
	// also, window will always be square, so x == y
	float cellSize = (float)window.getSize().x / GRID_DIMENSION;
	return sf::Vector2f(pos.x - fmodf(pos.x, cellSize), pos.y - fmodf(pos.y, cellSize));
}

/*************************************************************
* Function: snapToGrid()									*
* Description: Returns grid coordinates for object			*
* Input parameters: Object coords							*
* Returns: Grid coords									    *
* Preconditions: None								        *
* Postconditions: None									    *
*************************************************************/
sf::Vector2f Grid::snapToGrid(const sf::Vector2f& pos, const float objScale)
{
	float cellSize = objScale * 16;
	return sf::Vector2f(pos.x - fmodf(pos.x, cellSize), pos.y - fmodf(pos.y, cellSize));
}

/*************************************************************
* Function: getGridIndices() 								*
* Description: Returns the grid index of a position vec		*
* Input parameters: position vec							*
* Returns: Grid coords									    *
* Preconditions: None								        *
* Postconditions: None									    *
*************************************************************/
sf::Vector2i Grid::getGridIndices(const sf::Vector2f& pos, const sf::RenderWindow& window)
{
	float cellSize = (float)window.getSize().x / GRID_DIMENSION;
	return sf::Vector2i((int)floor(pos.x / cellSize), (int)floor(pos.y / cellSize));
}

/*************************************************************
* Function: getGridIndices()								*
* Description: Returns the grid index of an object	 		*
* Input parameters: object coords							*
* Returns: Grid coords									    *
* Preconditions: None								        *
* Postconditions: None									    *
*************************************************************/
sf::Vector2i Grid::getGridIndices(const sf::Vector2f& pos, const float objScale)
{
	// objScale = (float)windowDimension / (16 * Grid::getGridDimension());
	// objScale * 16 * Grid::getGridDimension() = windowDimension
	// gridDimension cancels out, so:
	float cellSize = (objScale * 16);
	return sf::Vector2i((int)floor(pos.x / cellSize), (int)floor(pos.y / cellSize));
}

/*************************************************************
* Function: getGridPos()									*
* Description: Returns the grid index of a pixel coord		*
* Input parameters: Pixel coord								*
* Returns: Grid coords									    *
* Preconditions: None								        *
* Postconditions: None									    *
*************************************************************/
sf::Vector2f Grid::getGridPos(int x, int y, const sf::RenderWindow& window)
{
	float cellSize = (float)window.getSize().x / GRID_DIMENSION;
	return sf::Vector2f((float)x * cellSize, (float)y * cellSize);
}


/*************************************************************
* Function: getGridPos()									*
* Description: Returns the grid index of an object with pixel*
* Input parameters: Object pixel coord						*
* Returns: Grid coords									    *
* Preconditions: None								        *
* Postconditions: None									    *
*************************************************************/
sf::Vector2f Grid::getGridPos(int x, int y, const float objScale)
{
	float cellSize = (objScale * 16);
	return sf::Vector2f((float)x * cellSize, (float)y * cellSize);
}
