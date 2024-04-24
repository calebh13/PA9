#include "CentipedeBody.hpp"
#include "Bullet.hpp"
#include "Player.hpp"

void CentipedeBody::collideWith(GameObject* other)
{
	// Bullets: Need to split (figure out status return val of collideWith)
	// Centipede parts, fleas, and spiders: don't care
	// Mushrooms: handled by CentipedeHead
	// Player: damage player
	Bullet* b = dynamic_cast<Bullet*>(other);
	if (b != nullptr)
	{
		b->hit();
		this->hit();
		return;
	}
	Player* p = dynamic_cast<Player*>(other);
	if (p != nullptr)
	{
		p->hit();
		return;
	}
}

action CentipedeBody::isDead(void) const
{
	if (health == 0)
	{
		if (this->getNodeBehind() == nullptr)
		{
			this->nodeInFront->setNodeBehind(nullptr);
			return static_cast<action>(DESTROY);
		}
		else
		{
			return static_cast<action>(SPLIT_CENTIPEDE);
		}
	}
	else return static_cast<action>(NOTHING);
}

void CentipedeBody::genNewPosition(const sf::RenderWindow& window)
{
	this->lastWaypoint = this->getPosition();
	glideTo(nodeInFront->getLastWaypoint().x, nodeInFront->getLastWaypoint().y);
}