#include "Player.hpp"

void Player::hit()
{
	lives -= 1;
	// maybe do some animation stuff as well, not sure where that should happen exactly
}

bool Player::isDead() const
{
	return lives == 0;
}

//float Player::getSpeedMult() const
//{
//	return 0.2f;
//}

void Player::move(sf::RenderWindow &gameWindow) // created 4/16 by Jace
{
	int mouseX = sf::Mouse::getPosition(gameWindow).x, mouseY = sf::Mouse::getPosition(gameWindow).y;

	std::cout << "Mouse X: " << mouseX << " " << mouseY << std::endl; // outputs mouse position to screen

	this->mousePosition = sf::Mouse::getPosition(gameWindow); // actually updates the mouth position within window 
	this->mouseVisual = gameWindow.mapPixelToCoords(this->mousePosition); // allows pixel to "follow" the mouse

	if (mouseX > MAX_X || mouseY > 1000 || mouseX < 0 || mouseY < MIN_Y) // bounds the mouse - the current texture is not centered so it appears as if it can go off
	{																	//  the bottom and right side but it cannot ( with proper texture) 
		if (mouseX < 0)
		{
			mouseVisual.x = 0;
		}
		else if (mouseX > MAX_X)
		{
			mouseVisual.x = MAX_X;
		}
		if (mouseY < MIN_Y)
		{
			mouseVisual.y = MIN_Y;
		}
		else if (mouseY > MAX_Y)
		{
			mouseVisual.y = MAX_Y;
		}
	}

	this->setPosition(mouseVisual); // sets postion of the sprite to mouse visual which gets its pos from mousePosition 

}

void Player::shoot(Bullet &bullets)
{
	bullets.setPosition(mouseVisual.x, mouseVisual.y);
	
}