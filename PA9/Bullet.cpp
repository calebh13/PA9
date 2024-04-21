#include "Bullet.hpp"

void Bullet::genNewPosition(const sf::RenderWindow& window)
{
	this->glideTo(this->getPosition().x, this->getPosition().y - 30);
}

void Bullet::collideWith(GameObject* other)
{
	CentipedeBody* cenBody = dynamic_cast<CentipedeBody*>(other);
	if (cenBody != nullptr)
	{
		this->collideWith(cenBody);
	}

	Mushroom* mushroom = dynamic_cast<Mushroom*>(other);
	if (mushroom != nullptr)
	{
		this->collideWith(mushroom);
	}


}


void Bullet::collideWith(CentipedeBody* cenBody)
{
	cenBody->hit();
}

void Bullet::collideWith(Mushroom* mushroom)
{
	this->health = 0;
	mushroom->hit();
}
