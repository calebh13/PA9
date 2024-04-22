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
		cenBody->hit();
		this->health = 0;
		return;
	}

	Mushroom* mushroom = dynamic_cast<Mushroom*>(other);
	if (mushroom != nullptr)
	{
		mushroom->hit();
		this->health = 0;
		return;
	}

	//not working
	CentipedeHead* centipedeHead = dynamic_cast<CentipedeHead*>(other);
	if (centipedeHead != nullptr)
	{
		centipedeHead->hit();
		this->health = 0;
		return;
	}

	Flea* flea = dynamic_cast<Flea*>(other);
	if (flea != nullptr)
	{
		flea->hit();
		this->health = 0;
		return;
	}

	//no collide with player

	Spider* spider = dynamic_cast<Spider*>(other);
	if (spider != nullptr)
	{
		spider->hit();
		this->health = 0;
		return;
	}

	


}