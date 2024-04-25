/*
	Caleb

	Description: This is the cpp file for the mushroom class

   History: 4/19/24 - Class was created and implimented initially by Caleb

*/
#include "Mushroom.hpp"
#include "Player.hpp"

/*************************************************************
* Function: hit()											*
* Description: Mushrooms ovverride hit. They take visible   *
*				damage.										*
* Input parameters: None									*
* Returns: None											    *
* Preconditions: N/A							            *
* Postconditions: N/A									    *
*************************************************************/
void Mushroom::hit()
{
	// Every time health decreases, 1/4th of the mushroom disappears (from bottom up)
	health -= 1;
	this->setTextureRect(sf::IntRect(0, 0, 16, (health * 4)));
}

/*************************************************************
* Function: heal()										    *
* Description: Mushrooms are healed by fleas				*
* Input parameters: None									*
* Returns: None											    *
* Preconditions: N/A							            *
* Postconditions: Mushroom gets healed  				    *
*************************************************************/
void Mushroom::heal(void)
{
	health = 4;
	//texture reset to non-damaged
	setTextureRect(sf::IntRect(0, 0, 16, health * 4));
}

/*************************************************************
* Function: collideWith()									*
* Description: Makes changes to game object depending on what*
				it has collided with.						*
* Input parameters: Pointer to object that was hit			*
* Returns: None											    *
* Preconditions: input pointer cannot be nullptr            *
* Postconditions: Object's parameters are changed on hit    *
*************************************************************/
void Mushroom::collideWith(GameObject* other)
{
	//Mushrooms are damaged by bullets
	Bullet* b = dynamic_cast<Bullet*>(other);
	if (b != nullptr)
	{
		this->hit();
		b->hit();
	}

	//If mushrooms are placed on top of each other (by flea) the newest mushroom is killed.
	//Only the strongest mushrooms may survive! 
	Mushroom* mushroom = dynamic_cast<Mushroom*>(other);
	if (mushroom != nullptr)
	{
		mushroom->hit();
	}

	//If a centipede hits a mushroom, it must bounce left, right, up, or down.
	CentipedeHead* cen = dynamic_cast<CentipedeHead*>(other);
	if (cen != nullptr && !cen->isMovingVertically()) // ignore centipede collisions if we're moving vertically
	{
		sf::Vector2i cen_indices = Grid::getGridIndices(cen->getPosition(), cen->getScale().x);
		sf::Vector2i m_indices = Grid::getGridIndices(this->getPosition(), this->getScale().x);
		dir mushroomDir = RIGHT; // just to initialize
		if (cen_indices.x < m_indices.x) mushroomDir = RIGHT;
		else if (cen_indices.x > m_indices.x) mushroomDir = LEFT;
		else if (cen_indices.y < m_indices.y) mushroomDir = DOWN;
		else if (cen_indices.y > m_indices.y) mushroomDir = UP;
		cen->bonkMushroom(mushroomDir);
	}

	//If mushrooms hit a player, they are returned to a valid position
	Player* p = dynamic_cast<Player*>(other);
	if (p != nullptr)
	{
		p->returnToValidPos();
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
void Mushroom::genNewPosition(const sf::RenderWindow& window)
{
	this->glideTo(this->getPosition().x, this->getPosition().y);
}
