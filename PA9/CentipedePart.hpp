#pragma once
#include "GameObject.hpp"

/*
Todo: add an "is paused" bool to make the centipede pause for a frame after hitting a mushroom.
That way the bodies won't get desynced from the head.
Maybe not a bool but probably something similar.
*/

enum dir
{
	UP, RIGHT, DOWN, LEFT, NONE
};

class CentipedePart : public GameObject
{
public:
	CentipedePart(unsigned int scale = 1, const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1, unsigned int interpolationFrames = 10, 
		dir curDir = dir::RIGHT) : GameObject(scale, pos, texture, health, interpolationFrames)
	{
		this->curDir = curDir;
		this->nodeBehind = nullptr;
		this->lastWaypoint = pos;
	}

	virtual void collideWith(GameObject* other) = 0;
	void setNodeBehind(CentipedePart* behind);
	CentipedePart* getNodeBehind(void) const;
	sf::Vector2f getLastWaypoint(void) const;
	void pause(void);
	void heal(void);
protected:
	dir curDir;
	sf::Vector2f lastWaypoint;
	CentipedePart* nodeBehind;
	virtual void genNewPosition(const sf::RenderWindow& window) = 0;
	void forceRegeneration(void);
};

void reverseDir(dir& d);