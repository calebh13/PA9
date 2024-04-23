#include "Mushroom.hpp"
#include "Player.hpp"

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

	CentipedeHead* cen = dynamic_cast<CentipedeHead*>(other);
	if (cen != nullptr)
	{
		sf::Vector2i cen_indices = Grid::getGridIndices(cen->getPosition(), cen->getScale().x);
		sf::Vector2i m_indices = Grid::getGridIndices(this->getPosition(), this->getScale().x);
		dir mushroomDir = RIGHT; // just to initialize
		if (cen_indices.x < m_indices.x) mushroomDir = RIGHT;
		else if (cen_indices.x > m_indices.x) mushroomDir = LEFT;
		else if (cen_indices.y < m_indices.y) mushroomDir = DOWN;
		else if (cen_indices.y > m_indices.y) mushroomDir = UP;
		cen->bonkMushroom(mushroomDir);
	}

	Player* p = dynamic_cast<Player*>(other);
	if (p != nullptr)
	{
		p->returnToValidPos();
	}
}

void Mushroom::genNewPosition(const sf::RenderWindow& window)
{
	this->glideTo(this->getPosition().x, this->getPosition().y);
}
