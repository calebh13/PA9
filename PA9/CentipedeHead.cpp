#include "CentipedeHead.hpp"
#include "Bullet.hpp"
#include "Player.hpp"

void CentipedeHead::collideWith(GameObject* other)
{
	Mushroom* m = dynamic_cast<Mushroom*>(other);
	if (m != nullptr && !isMovingVertically())
	{
		sf::Vector2i cen_indices = Grid::getGridIndices(this->getPosition(), this->getScale().x);
		sf::Vector2i m_indices = Grid::getGridIndices(m->getPosition(), m->getScale().x);
		dir mushroomDir = RIGHT; // just to initialize
		if (cen_indices.x < m_indices.x) mushroomDir = RIGHT;
		else if (cen_indices.x > m_indices.x) mushroomDir = LEFT;
		else if (cen_indices.y < m_indices.y) mushroomDir = DOWN;
		else if (cen_indices.y > m_indices.y) mushroomDir = UP;
		this->bonkMushroom(mushroomDir);
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

void CentipedeHead::bonkMushroom(dir mushroomDir)
{
	// Movement logic after hitting mushroom goes here
	this->pause();
	this->moveFrame = this->interpolationFrames; // force genNewPosition to be called
	reverseDir(horizDir);
	if (mushroomDir == DOWN || mushroomDir == UP)
	{
		std::cout << "Changing to horiz dir. Mushroom dir: " << mushroomDir << "\n";
		forbiddenDir = mushroomDir;
		curDir = horizDir;
	}
	else
	{
		std::cout << "Changing to vertGoalDir. Mushroom dir: " << mushroomDir << "\n";
		curDir = vertGoalDir;
	}
}

bool CentipedeHead::isMovingVertically(void) const
{
	return movingVertically;
}

void CentipedeHead::genNewPosition(const sf::RenderWindow& window)
{
	sf::Vector2f pos = this->getPosition();
	//maybe snap to grid? like so:
	this->lastWaypoint = Grid::snapToGrid(pos, window);

	sf::Vector2i indices = Grid::getGridIndices(pos, window);

	bool foundValidChoice = false;
	while (!foundValidChoice)
	{
		// NON DETERMINISTIC MOVEMENT: EEK!
		/*if (curDir == forbiddenDir)
		{
			curDir = static_cast<dir>(rand() % 4);
		}*/
		switch (curDir)
		{
		case dir::UP:
			if (indices.y - 1 < 0) // trying to move to the top of the screen
			{
				reverseDir(horizDir); // alternate horiz
				reverseDir(vertGoalDir); // start moving down the screen as well
				curDir = horizDir; // next move should be horizontal though
			}
			else
			{
				foundValidChoice = true;
				movingVertically = true;
				//std::cout << "Moving up\n";
				glideTo(pos.x, Grid::getGridPos(indices.x, indices.y - 1, window).y);
				curDir = horizDir; // can only move down once
			}
			break;
		case dir::RIGHT:
			if (indices.x + 1 >= Grid::getGridDimension())
			{
				curDir = vertGoalDir; // start going down (or up if that's the goal) since we hit the side of the screen
				reverseDir(horizDir); // alternate 
			}
			else
			{
				foundValidChoice = true;
				movingVertically = false;
				//std::cout << "Moving right\n";
				glideTo(Grid::getGridPos(indices.x + 1, indices.y, window).x, pos.y);
			}
			break;
		case dir::DOWN:
			if (indices.y + 1 >= Grid::getGridDimension())
			{
				reverseDir(horizDir); // alternate horizontal direction
				reverseDir(vertGoalDir); // also change vertical direction, since we've reached the top
				curDir = horizDir;
			}
			else
			{
				foundValidChoice = true;
				movingVertically = true;
				//std::cout << "Moving down\n";
				glideTo(pos.x, Grid::getGridPos(indices.x, indices.y + 1, window).y);
				curDir = horizDir; // can only move down once
			}
			break;
		case dir::LEFT:
			if (indices.x - 1 < 0)
			{
				reverseDir(horizDir);
				curDir = vertGoalDir; // start going down, since we hit the side of the screen
			}
			else
			{
				foundValidChoice = true;
				movingVertically = false;
				//std::cout << "Moving left\n";
				glideTo(Grid::getGridPos(indices.x - 1, indices.y, window).x, pos.y);
			}
			break;
		}
	}
	forbiddenDir = NONE;
	
}

void CentipedeHead::incrementDir(dir& d)
{
	d = static_cast<dir>((d + 1) % 4);
}

void CentipedeHead::reverseDir(dir& d)
{
	d = static_cast<dir>((d + 2) % 4);
}