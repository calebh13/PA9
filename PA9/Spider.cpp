/*
	Jace, Lucas

	Description: This is the cpp file for the Spider Class

   History: 4/19/24 - Class was created and implimented initially by Jace
			4/21/24 - Code refactored by Lucas

*/
#include "Spider.hpp"


/*************************************************************
* Function: collideWith()									*
* Description: Makes changes to game object depending on what*
				it has collided with.						*
* Input parameters: Pointer to object that was hit			*
* Returns: None											    *
* Preconditions: input pointer cannot be nullptr            *
* Postconditions: Object's parameters are changed on hit    *
*************************************************************/
void Spider::collideWith(GameObject* other)
{
	Bullet* bullet = dynamic_cast<Bullet*>(other);
	if (bullet != nullptr)
	{
		bullet->hit();
		this->health = 0;
		return;
	}
	
	Player* player = dynamic_cast<Player*>(other);
	if (player != nullptr)
	{
		player->hit();
		this->health = 0;
		return;
	}
}

/*************************************************************
* Function: genRandomDir()   								*
* Description: Generates a random direction for the spider  *
				to travel in.								*
* Input parameters: None									*
* Returns: None											    *
* Preconditions: None							            *
* Postconditions: Spider's velocities are set			    *
*************************************************************/
void Spider::genRandomDir()
{
	int randomDir = rand() % 8; // 0, 1, 2, or 3
	switch (randomDir)
	{
	case 0:
		xDir = 0, yDir = -1;// Up
		break;
	case 1:
		xDir = 0, yDir = 1; // Down
		break;
	case 2:
		xDir = 1, yDir = 0; // Right
		break;
	case 3:
		xDir = -1, yDir = 0; // Left
		break;
	case 4: 
		xDir = 1, yDir = -1; // Up Right
	case 5: 
		xDir = -1, yDir = -1; // Up Left
		break;
	case 6:
		xDir = 1, yDir = 1; // Down Right
		break;
	case 7: 
		xDir = -1, yDir = 1; // Down left
	}
}

/*************************************************************
* Function: genNewPosition()                                *
* Description: This function sends the object to its new pos*
* Input parameters: Window where object is drawn		    *
* Returns: Nothing                                          *
* Preconditions: Object and window must exist               *
* Postconditions: Object position is changed                *
*************************************************************/
void Spider::genNewPosition(const sf::RenderWindow& window)
{
	//Spider has a chance to re-roll it's movement
	int chance = rand() % 4;
	if (chance == 2)
	{
		this->genRandomDir();
	}

	//Checks to see if the spider is within bounds. If not, it's velocities are reset.
	sf::Vector2i indices = Grid::getGridIndices(this->getPosition(), this->getScale().x);
	if (this->getPosition().x > window.getSize().x)
	{
		this->setPosition(1, this->getPosition().y);
		xDir = 1;
	}
	if (this->getPosition().x < 0)
	{
		this->setPosition(window.getSize().x, this->getPosition().y);
		xDir = -1;
	}
	if (indices.y > Grid::getGridDimension())
	{
		yDir = -1;
	}
	if (indices.y < Grid::getGridDimension() * .85)
	{
		yDir = 1;
	}

	//Once the spider is moving in a legal direction, it is sent there using glideTo
	this->glideTo(this->getPosition().x + (50 * xDir), this->getPosition().y + (50 * yDir));
}

