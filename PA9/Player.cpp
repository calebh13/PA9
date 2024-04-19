#include "Player.hpp"
#include "Bullet.hpp"
#include "Grid.hpp"
#include <iostream>

void Player::hit()
{
	lives -= 1;
	// maybe do some animation stuff as well, not sure where that should happen exactly
}

bool Player::isDead() const
{
	return lives == 0;
}

// TODO: change this to be update(), so we can call update() on everything
void Player::move(sf::RenderWindow &gameWindow) // created 4/16 by Jace, modified 4/18 by Caleb
{
	// exactly equal to localBounds.width because origin of local bounds is (0,0)
	// and remember player is square	
	float playerSize = this->getLocalBounds().width * this->getScale().x;
	// however, player is not centered
	float xMax = gameWindow.getSize().x - (0.5 * playerSize); 
	float xMin = 0 + (0.5 * playerSize);
	// 24/32 below so player can access bottom quarter of screen:
	float yMin = Grid::getGridPos(sf::Vector2i(0, 24), gameWindow).y - (0.5 * playerSize);
	float yMax = gameWindow.getSize().y - (0.5 * playerSize);

	this->mousePosition = sf::Mouse::getPosition(gameWindow); // "real" position of the mouse

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

	this->setPosition(mouseVisual); // sets position of the sprite to mouse visual which gets its pos from mousePosition 
	//std::cout << "MouseX: " << mouseVisual.x << ", MouseY: " << mouseVisual.y << "\n";
}

bool Player::canShoot(void) const
{
	return shotCooldown == 0;
}