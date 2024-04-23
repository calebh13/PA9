#include "CentipedeHead.hpp"
#include "Bullet.hpp"
#include "Player.hpp"

void CentipedeHead::collideWith(GameObject* other)
{
	return;
	Mushroom* m = dynamic_cast<Mushroom*>(other);
	if (m != nullptr)
	{
		// Movement logic for now is going to be if you touch a mushroom, just cycle directions
		//this->nextDir = static_cast<dir>((nextDir + 1) % 4);
		return;
	}

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

// if we get some centipede-exclusive action enum from any isDead() call, 
// then we know for sure we can cast to a CentipedePart* inside GameWrapper
action CentipedeHead::isDead(void) const
{
	if (health == 0)
	{
		if (this->getNodeBehind() == nullptr)
		{
			return static_cast<action>(CENTIPEDE_DESTROYED);
		}
		else
		{
			return static_cast<action>(CENTIPEDE_HEAD_MOVE);
		}
	}
	else
	{
		return static_cast<action>(NOTHING);
	}
}

void CentipedeHead::genNewPosition(const sf::RenderWindow& window)
{
	sf::Vector2f pos = this->getPosition();
	//maybe snap to grid?:
	//this->lastWaypoint = Grid::snapToGrid(pos, window);
	this->lastWaypoint = pos;

	sf::Vector2i indices = Grid::getGridIndices(pos, window);

	switch (nextDir)
	{
	case dir::UP:
		glideTo(pos.x, Grid::getGridPos(indices.x, indices.y - 1, window).y);
		break;
	case dir::RIGHT:
		glideTo(Grid::getGridPos(indices.x + 1, indices.y, window).x, pos.y);
		break;
	case dir::DOWN:
		glideTo(pos.x, Grid::getGridPos(indices.x, indices.y + 1, window).y);
		break;
	case dir::LEFT:
		glideTo(Grid::getGridPos(indices.x - 1, indices.y, window).x, pos.y);
		break;
	}

}