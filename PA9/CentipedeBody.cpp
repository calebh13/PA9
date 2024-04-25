/*
	Caleb

	Description: CPP File for centipede

// History: 4/24/24 - Class was created and implimented initially by Caleb

*/
#include "CentipedeBody.hpp"
#include "Bullet.hpp"
#include "Player.hpp"


/*************************************************************
* Function: collideWith()									*
* Description: Makes changes to game object depending on what*
				it has collided with.						*
* Input parameters: Pointer to object that was hit			*
* Returns: None											    *
* Preconditions: input pointer cannot be nullptr            *
* Postconditions: Object's parameters are changed on hit    *
*************************************************************/
void CentipedeBody::collideWith(GameObject* other)
{
	// Bullets: Need to split (figure out status return val of collideWith)
	// Centipede parts, fleas, and spiders: don't care
	// Mushrooms: handled by CentipedeHead
	// Player: damage player
	Bullet* b = dynamic_cast<Bullet*>(other);
	if (b != nullptr)
	{
		b->hit();
		this->hit();
		return;
	}
	Player* p = dynamic_cast<Player*>(other);
	if (p != nullptr)
	{
		p->hit();
		return;
	}
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
action CentipedeBody::isDead(void) const
{
	if (health == 0)
	{
		if (this->getNodeBehind() == nullptr)
		{
			this->nodeInFront->setNodeBehind(nullptr);
			return static_cast<action>(DESTROY);
		}
		else
		{
			return static_cast<action>(CENTIPEDE_SHOT);
		}
	}
	else return static_cast<action>(NOTHING);
}

/*************************************************************
* Function: setFrontNode()                                  *
* Description: Sets the new front node of the centipede node*
* Input parameters: Pointer to new node         		    *
* Returns: Nothing                                          *
* Preconditions: Pointer cannot be null                     *
* Postconditions: Front is set				                *
*************************************************************/
void CentipedeBody::setFrontNode(CentipedePart* frontNode)
{
	this->nodeInFront = frontNode;
}

/*************************************************************
* Function: getFrontNode()                                  *
* Description: Sets the new front node of the centipede node*
* Input parameters: None     								*
* Returns: Head Node                                        *
* Preconditions: None					                    *
* Postconditions: None      				                *
*************************************************************/
CentipedePart* CentipedeBody::getFrontNode(void) const
{
	return this->nodeInFront;
}

/*************************************************************
* Function: genNewPosition()                                *
* Description: This function sends the object to its new pos*
* Input parameters: Window where object is drawn		    *
* Returns: Nothing                                          *
* Preconditions: Object and window must exist               *
* Postconditions: Object position is changed                *
*************************************************************/
void CentipedeBody::genNewPosition(const sf::RenderWindow& window)
{
	this->lastWaypoint = this->getPosition();
	glideTo(nodeInFront->getLastWaypoint().x, nodeInFront->getLastWaypoint().y);
}