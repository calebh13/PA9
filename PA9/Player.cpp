#include "Player.hpp"
#include "Grid.hpp"

void Player::hit()
{
	lives -= 1;
	// maybe do some animation stuff as well, not sure where that should happen exactly
}

bool Player::isDead() const
{
	return lives == 0;
}

void Player::move(sf::RenderWindow &gameWindow) // created 4/16 by Jace, modified 4/18 by Caleb
{
	// exactly equal to localBounds.width because origin of local bounds is (0,0)
	// and remember player is square	
	int playerSize = this->getLocalBounds().width * this->getScale().x;
	// however, player is not centered
	int xMax = gameWindow.getSize().x - (int)(0.5 * playerSize); 
	int xMin = 0 + (int)(0.5 * playerSize);
	// 24/32 below so player can access bottom quarter of screen:
	int yMin = 0 - (int)(0.5 * playerSize) + Grid::getGridPos(sf::Vector2i(0, 24), gameWindow).y;
	int yMax = gameWindow.getSize().y - (int)(0.5 * playerSize);

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

bool Player::canShoot(void)
{
	return shotCooldown == 0;
}