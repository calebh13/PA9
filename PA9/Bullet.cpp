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
		this->collide(cenBody);
		return;
	}

	Mushroom* mushroom = dynamic_cast<Mushroom*>(other);
	if (mushroom != nullptr)
	{
		this->collide(mushroom);
	}


}


void Bullet::collide(CentipedeBody* cenBody)
{
	cenBody->hit();
}

void Bullet::collide(Mushroom* mushroom)
{
	this->health = 0;
	mushroom->hit();
}
