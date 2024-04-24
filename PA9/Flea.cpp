#include "Flea.hpp"

void Flea::collideWith(GameObject* other)
{
	Bullet* bullet = dynamic_cast<Bullet*>(other);
	if (bullet != nullptr)
	{
		bullet->hit();
		this->hit();
		return;
	}

	Player* player = dynamic_cast<Player*>(other);
	if (player != nullptr)
	{
		player->hit();
		return;
	}
}

void Flea::hit(void)
{
	this->setPosition(Grid::getGridPos(0, 30, this->getScale().x));
}

action Flea::isDead(void) const
{
	return static_cast<action>(NOTHING);
}

void Flea::genNewPosition(const sf::RenderWindow& window)
{
	if ((this->getPosition().y) > (Grid::getGridPos(0, Grid::getGridDimension() + 6, this->getScale().x).y))
	{
		// If offscreen, stay at same position
		std::cout << "OOB. Flea leaving\n";
		this->glideTo(Grid::getGridPos(30, 30, this->getScale().x).x, Grid::getGridPos(30, 30, this->getScale().x).y);
	}
	else
	{
		// Otherwise move down
		this->glideTo(this->getPosition().x, this->getPosition().y + 5);
	}
}
