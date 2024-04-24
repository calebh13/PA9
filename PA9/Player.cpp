#include "Player.hpp"
#include "Bullet.hpp"
#include "Grid.hpp"
#include <iostream>

void Player::hit()
{
	health -= 1;
}

enum action Player::isDead() const
{
	if (health == 0)
	{
		return static_cast<action>(RESPAWN);
	}
	else if(lives == 0)
	{
		return static_cast<action>(GAME_OVER);
	}
}

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
	//std::cout << "Mouse: (" << movementInstructions[0].x << ", " << movementInstructions[0].y << ")\n";
}

bool Player::shoot(void)
{
	if (shotCooldown == 0)
	{
		shotCooldown = 10;
		return true;
	}
	else return false;
}

void Player::reduceShotTimer(void)
{
	if (shotCooldown != 0)
	{
		shotCooldown--;
	}
}

void Player::returnToValidPos(void)
{
	this->setPosition(lastValidPosition);
}

void Player::collideWith(GameObject* other)
{
	Mushroom* m = dynamic_cast<Mushroom*>(other);
	if (m != nullptr)
	{
		this->returnToValidPos();
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


}
