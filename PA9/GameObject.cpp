#pragma once
#include "GameObject.hpp"
#include "CentipedeHead.hpp"

/*************************************************************
* Function: hit()											*
* Description: Removes health from object					*
* Input parameters: None									*
* Returns: None											    *
* Preconditions: N/A							            *
* Postconditions: Health changed      					    *
*************************************************************/
void GameObject::hit(void)
{
	health -= 1;
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
action GameObject::isDead(void) const
{
	if (health == 0)
	{
		return static_cast<action>(DESTROY);
	}
	else return static_cast<action>(NOTHING);
}


/*************************************************************
* Function: glideTo										    *
* Description: Gives object a collection of discrete		*
				movement steps to reach a point on screen   *
* Input parameters: Destination coords						*
* Returns: None											    *
* Preconditions: destination must be in bounds	            *
* Postconditions: Object is given instructions               *
*************************************************************/
void GameObject::glideTo(float x, float y) {
	//Two Vectors that hold the x and y coordinates for each step
	movementInstructions = std::vector<sf::Vector2f>(interpolationFrames);

	//Glides starting at current pos
	const sf::Vector2f& currentPosition = this->getPosition();

	//Breaks movements into steps and sdds to instruction array
	for (int i = 1; i <= interpolationFrames; i++) {
		movementInstructions[i - 1].x = currentPosition.x + (float)i * ((x - currentPosition.x) / interpolationFrames);
		movementInstructions[i - 1].y = currentPosition.y + (float)i * ((y - currentPosition.y) / interpolationFrames);
	}

	//When given new instructions, the object resets to the first frame of movement
	moveFrame = 0;
}

/*************************************************************
* Function: update()									    *
* Description: updates the objects position on screen    	*
* Input parameters: Window where it's drawn 	    		 *
* Returns: None											    *
* Preconditions: Game Object's frames are valid             *
* Postconditions: Game object is moved		                *
*************************************************************/
void GameObject::update(const sf::RenderWindow& window) {
	// We will need to generate new instructions once we have been moving for time equal to interpolationFrames
	if (moveFrame == -1)
	{
		// Always generate a new position the first time an object is created
		moveFrame = 0;
		genNewPosition(window);
	}
	else if (this->moveFrame < ((int)(interpolationFrames) - 1)) 
	{
		this->moveFrame += 1;
	} 
	else 
	{
		genNewPosition(window);
	}

	this->setPosition(movementInstructions[moveFrame]);
}

/*************************************************************
* Function: heal()											*
* Description: Adds health to an object 					*
* Input parameters: None									*
* Returns: None											    *
* Preconditions: N/A							            *
* Postconditions: Health changed      					    *
*************************************************************/
void GameObject::heal(void)
{
}

/*************************************************************
* Function: genNewPosition()                                *
* Description: This function sends the object to its new pos*
* Input parameters: Window where object is drawn		    *
* Returns: Nothing                                          *
* Preconditions: Object and window must exist               *
* Postconditions: Object position is changed                *
*************************************************************/
void GameObject::genNewPosition(const sf::RenderWindow& window)
{
	//Default position
	movementInstructions[0] = sf::Vector2f(0, 0);
}
