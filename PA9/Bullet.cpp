#include "Bullet.hpp"

void Bullet::genNewPosition(const sf::RenderWindow& window)
{
	this->glideTo(this->getPosition().x, this->getPosition().y - 30);
}

action Bullet::isDead(void) const
{
	if (this->getPosition().y < 0 || this->health == 0) return static_cast<enum action>(DESTROY);
	else return static_cast<enum action>(NOTHING);
}

void Bullet::collideWith(GameObject* other)
{
	CentipedeBody* cenBody = dynamic_cast<CentipedeBody*>(other);
	if (cenBody != nullptr)
	{
		cenBody->hit();
		this->hit();
		return;
	}

	Mushroom* mushroom = dynamic_cast<Mushroom*>(other);
	if (mushroom != nullptr)
	{
		mushroom->hit();
		this->hit();
		return;
	}

	CentipedeHead* centipedeHead = dynamic_cast<CentipedeHead*>(other);
	if (centipedeHead != nullptr)
	{
		centipedeHead->hit();
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

	//no collide with player

	Spider* spider = dynamic_cast<Spider*>(other);
	if (spider != nullptr)
	{
		spider->hit();
		this->hit();
		return;
	}
}