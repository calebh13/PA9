/*
	Jace
	4/22/24

	Description: This is the cpp file for the bullet class

// History: 4/22/24 - Class was created and implimented initially

*/
#include "Bullet.hpp"


/*************************************************************
* Function: genNewPosition()                                *               
* Description: This function sends the object to its new pos*
* Input parameters: Window where object is drawn		    *
* Returns: Nothing                                          *
* Preconditions: Object and window must exist               *
* Postconditions: Object position is changed                *
*************************************************************/
void Bullet::genNewPosition(const sf::RenderWindow& window)
{
	this->glideTo(this->getPosition().x, this->getPosition().y - 30);
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
action Bullet::isDead(void) const
{
	//Bullets are killed if they leave bounds or hit something
	if (this->getPosition().y < 0 || this->health == 0) return static_cast<enum action>(DESTROY);
	else return static_cast<enum action>(NOTHING);
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
void Bullet::collideWith(GameObject* other)
{
	//Dynanmically casts "other" as each object. If the cast returns anything other than
	//A nullptr, then we know that "other" was this type of object.
	//This process is repeated for every object that has collision.

	//Centipedes take damage from bullets and the bullet dies
	CentipedeBody* cenBody = dynamic_cast<CentipedeBody*>(other);
	if (cenBody != nullptr)
	{
		cenBody->hit();
		this->hit();
		return;
	}

	//Mushrooms take damage from bullets and the bullet dies
	Mushroom* mushroom = dynamic_cast<Mushroom*>(other);
	if (mushroom != nullptr)
	{
		mushroom->hit();
		this->hit();
		return;
	}

	//Centipedes take damage from bullets and the bullet dies
	CentipedeHead* centipedeHead = dynamic_cast<CentipedeHead*>(other);
	if (centipedeHead != nullptr)
	{
		centipedeHead->hit();
		this->hit();
		return;
	}

	//Fleas take damage from bullets and the bullet dies
	Flea* flea = dynamic_cast<Flea*>(other);
	if (flea != nullptr)
	{
		flea->hit();
		this->hit();
		return;
	}

	//Spiders take damage from bullets and the bullet dies
	Spider* spider = dynamic_cast<Spider*>(other);
	if (spider != nullptr)
	{
		spider->hit();
		this->hit();
		return;
	}
}