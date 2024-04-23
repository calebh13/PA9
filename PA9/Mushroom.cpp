#include "Mushroom.hpp"

// Every time health decreases, 1/4th of the mushroom disappears (from bottom up)
void Mushroom::hit()
{
	health -= 1;
	this->setTextureRect(sf::IntRect(0, 0, 16, (health * 4)));
}

void Mushroom::heal(void)
{
	health = 4;
	setTextureRect(sf::IntRect(0, 0, 16, health * 4));
}

void Mushroom::collideWith(GameObject* other)
{
	Bullet* b = dynamic_cast<Bullet*>(other);
	if (b != nullptr)
	{
		this->hit();
		b->hit();
	}
}

void Mushroom::genNewPosition(const sf::RenderWindow& window)
{
	this->glideTo(this->getPosition().x, this->getPosition().y);
}
