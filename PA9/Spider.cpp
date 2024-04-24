#include "Spider.hpp"

void Spider::collideWith(GameObject* other)
{
	Bullet* bullet = dynamic_cast<Bullet*>(other);
	if (bullet != nullptr)
	{
		bullet->hit();
		this->health = 0;
		return;
	}
	
	Player* player = dynamic_cast<Player*>(other);
	if (player != nullptr)
	{
		player->hit();
		this->health = 0;
		return;
	}
}

void Spider::genRandomDir()
{
	int randomDir = rand() % 8; // 0, 1, 2, or 3
	switch (randomDir)
	{
	case 0:
		xDir = 0, yDir = -1;// Up
		break;
	case 1:
		xDir = 0, yDir = 1; // Down
		break;
	case 2:
		xDir = 1, yDir = 0; // Right
		break;
	case 3:
		xDir = -1, yDir = 0; // Left
		break;
	case 4: 
		xDir = 1, yDir = -1; // Up Right
	case 5: 
		xDir = -1, yDir = -1; // Up Left
		break;
	case 6:
		xDir = 1, yDir = 1; // Down Right
		break;
	case 7: 
		xDir = -1, yDir = 1; // Down left
	}
}

void Spider::genNewPosition(const sf::RenderWindow& window)
{
	int chance = rand() % 4;
	if (chance == 2)
	{
		this->genRandomDir();
	}
	sf::Vector2i indices = Grid::getGridIndices(this->getPosition(), this->getScale().x);
	if (this->getPosition().x > window.getSize().x)
	{
		this->setPosition(1, this->getPosition().y);
		xDir = 1;
	}
	if (this->getPosition().x < 0)
	{
		this->setPosition(window.getSize().x, this->getPosition().y);
		xDir = -1;
	}
	if (indices.y > Grid::getGridDimension())
	{
		yDir = -1;
	}
	if (indices.y < Grid::getGridDimension() * .85)
	{
		yDir = 1;
	}
	this->glideTo(this->getPosition().x + (50 * xDir), this->getPosition().y + (50 * yDir));
}

