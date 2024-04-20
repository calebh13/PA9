#include "Mushroom.hpp"

// Every time health decreases, 1/4th of the mushroom disappears (from bottom up)
void Mushroom::hit()
{
	health -= 1;
	this->setTextureRect(sf::IntRect(0, 0, 16, (health * 4)));
}

void Mushroom::genNewPosition(const sf::RenderWindow& window)
{
	this->movementInstructions[0] = this->getPosition();
}
