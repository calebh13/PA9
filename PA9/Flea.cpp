/*
	Elliot, Caleb

	Description: This is the cpp file for the Flea Class

   History: 4/22/24 - Class was created and implimented initially by Elliot
			4/23/24 - Some code was refactord and collision added by Caleb

*/
#include "Flea.hpp"


/*************************************************************
* Function: collideWith()									*
* Description: Makes changes to game object depending on what*
				it has collided with.						*
* Input parameters: Pointer to object that was hit			*
* Returns: None											    *
* Preconditions: input pointer cannot be nullptr            *
* Postconditions: Object's parameters are changed on hit    *
*************************************************************/
void Flea::collideWith(GameObject* other)
{
	//Fleas die to bullets
	Bullet* bullet = dynamic_cast<Bullet*>(other);
	if (bullet != nullptr)
	{
		bullet->hit();
		this->hit();
		return;
	}

	//Players die to fleas
	Player* player = dynamic_cast<Player*>(other);
	if (player != nullptr)
	{
		player->hit();
		return;
	}
}

/*************************************************************
* Function: hit()											*
* Description: Fleas ovverride hit. They disappear from screen*
* Input parameters: None									*
* Returns: None											    *
* Preconditions: N/A							            *
* Postconditions: N/A									    *
*************************************************************/
void Flea::hit(void)
{
	this->setPosition(Grid::getGridPos(200, 200, this->getScale().x));
}

/*************************************************************
* Function: isDead()									    *
* Description: Gives instructions on whether or not to kill a*
				given game object.							*
* Input parameters: None									 *
* Returns: Action enum (See Game Object for definition)     *
* Preconditions: Game Object must exist                     *
* Postconditions: Instructions are returned                 *
*************************************************************/
action Flea::isDead(void) const
{
	//The same flea exists for the whole game. The sun never sets on the flea empire
	return static_cast<action>(NOTHING);
}

/*************************************************************
* Function: genNewPosition()                                *
* Description: This function sends the object to its new pos*
* Input parameters: Window where object is drawn		    *
* Returns: Nothing                                          *
* Preconditions: Object and window must exist               *
* Postconditions: Object position is changed                *
*************************************************************/
void Flea::genNewPosition(const sf::RenderWindow& window)
{
	if ((this->getPosition().y) > (Grid::getGridPos(0, Grid::getGridDimension() + 6, this->getScale().x).y))
	{
		// If offscreen, stay at same position
		this->glideTo(Grid::getGridPos(32, 32, this->getScale().x).x, Grid::getGridPos(32, 32, this->getScale().x).y);
	}
	else
	{
		// Otherwise move down
		this->glideTo(this->getPosition().x, this->getPosition().y + 5);
	}
}
