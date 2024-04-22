#include "Bullet.hpp"
#include "Mushroom.hpp"
#include "Spider.hpp"

void Bullet::genNewPosition(const sf::RenderWindow& window)
{
	this->glideTo(this->getPosition().x, this->getPosition().y - 30);
}

void Bullet::collideWith(GameObject* other)
{
	Mushroom* m = dynamic_cast<Mushroom*>(other);
	if (m != nullptr)
	{

	}
	Spider* s = dynamic_cast<Spider*>(other);
}