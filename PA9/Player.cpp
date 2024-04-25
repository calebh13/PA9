/*
	Caleb, Lucas, Jace

	Description: This is the cpp file for the Player Class

   History: 4/17/24 - Class was created initially by Lucas with rudamentary movement
			4/19/24 - Movement refactored and shots added by Jace
			4/20/24 - Collision added by Caleb

*/
#include "Player.hpp"
#include "Bullet.hpp"
#include "Grid.hpp"

/*************************************************************
* Function: hit()											*
* Description: Players ovverride hit.						*
* Input parameters: None									*
* Returns: None											    *
* Preconditions: N/A							            *
* Postconditions: Health changed      					    *
*************************************************************/
void Player::hit()
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
enum action Player::isDead() const
{
	//Players will die, or end the game
	if (health == 0)
	{
		if (lives == 0)
		{
			return static_cast<action>(GAME_OVER);
		}
		else
		{
			return static_cast<action>(RESPAWN);
		}
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
void Player::genNewPosition(const sf::RenderWindow& window)
{
	// Store lastvalidpos *before* making any changes
	this->lastValidPosition = this->getPosition();

	// size is exactly equal to localBounds.width because origin of local bounds is (0,0)
	// and remember player is square	
	float playerSize = this->getLocalBounds().width * this->getScale().x;
	// however, player is not centered
	float xMax = window.getSize().x - (0.5 * playerSize);
	float xMin = 0 + (0.5 * playerSize);
	// 18/24 so player can access bottom quarter of screen
	float yMin = Grid::getGridPos(0, 18, window).y - (0.5 * playerSize);
	float yMax = window.getSize().y - (0.5 * playerSize);

	this->mousePosition = sf::Mouse::getPosition(window); // "real" position of the mouse

	// X coord bound checking:
	if (this->mousePosition.x < xMin)
		this->mouseVisual.x = xMin;
	else if (this->mousePosition.x > xMax)
		this->mouseVisual.x = xMax;
	else
		this->mouseVisual.x = this->mousePosition.x;

	// Y coord bound checking:
	if (this->mousePosition.y < yMin)
		this->mouseVisual.y = yMin;
	else if (this->mousePosition.y > yMax)
		this->mouseVisual.y = yMax;
	else
		this->mouseVisual.y = this->mousePosition.y;

	this->movementInstructions[0] = mouseVisual;
}

/*************************************************************
* Function: shoot()                                         *
* Description: lets the player spawn a bullet object        *
* Input parameters: None								    *
* Returns: boolean representing whether the player is		*
			allowed to shoot								*
* Preconditions: Player must exist			                *
* Postconditions: NA					                    *
*************************************************************/
bool Player::shoot(void)
{
	//Simple frame timer
	if (shotCooldown == 0)
	{
		shotCooldown = 10;
		return true;
	}
	else return false;
}

/*************************************************************
* Function: reduceShotTimer()                               *
* Description: decriments the players shot timer            *
* Input parameters: None								    *
* Returns: None												*
* Preconditions: Player must exist			                *
* Postconditions: Shot timer reduced                        *
*************************************************************/
void Player::reduceShotTimer(void)
{
	if (shotCooldown != 0)
	{
		shotCooldown--;
	}
}

/*************************************************************
* Function: returnToValidPos()                              *
* Description: Returns to valid position				    *
* Input parameters: None								    *
* Returns: None												*
* Preconditions: None						                *
* Postconditions: Returns to last valid position            *
*************************************************************/
void Player::returnToValidPos(void)
{
	this->setPosition(lastValidPosition);
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
void Player::collideWith(GameObject* other)
{
	//Players die when touching anything except a mushroom. 
	//If touching mushroom, sent to valid pos
	Mushroom* m = dynamic_cast<Mushroom*>(other);
	if (m != nullptr)
	{
		this->returnToValidPos();
		std::cout << "Happening";
		return;
	}

	CentipedePart* cen = dynamic_cast<CentipedePart*>(other);
	if (cen != nullptr)
	{
		cen->hit();
		this->hit();
		return;
	}

	Flea* flea = dynamic_cast<Flea*>(other);
	if (flea != nullptr)
	{
		flea->hit();
		this->hit();
		return;
	}
	Spider* spider = dynamic_cast<Spider*>(other);
	if (spider != nullptr)
	{
		spider->hit();
		this->hit();
		return;
	}


}
