#pragma once
#include "GameObject.hpp"

enum dir
{
	UP, RIGHT, DOWN, LEFT
};

class CentipedePart : public GameObject
{

public:
	CentipedePart(unsigned int scale = 1, const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1, unsigned int interpolationFrames = 10, enum dir d = dir::DOWN)
		: GameObject(scale, pos, texture, health, interpolationFrames)
	{
		this->nextDir = d;
		this->lastWaypoint = pos;
		nodeBehind = nullptr;
	}

	void collideWith(GameObject* other) = 0;
	void setNodeBehind(CentipedePart* behind);
	CentipedePart* getNodeBehind(void) const;
	sf::Vector2f getLastWaypoint(void) const;
protected:
	dir nextDir;
	sf::Vector2f lastWaypoint;
	CentipedePart* nodeBehind;
	void genNewPosition(const sf::RenderWindow& window) = 0;
};