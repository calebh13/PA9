#pragma once
#include "GameObject.hpp"
#include "Grid.hpp"
#include "CentipedePart.hpp"


class CentipedeHead : public CentipedePart
{

public:
	CentipedeHead(unsigned int scale = 1, const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1, unsigned int interpolationFrames = 10, dir curDir = RIGHT,
		dir horizDir = RIGHT, dir vertGoalDir = DOWN) : CentipedePart(scale, pos, texture, health, interpolationFrames, curDir)
	{
		this->horizDir = horizDir;
		this->vertGoalDir = vertGoalDir;
		this->movingHorizontal = (curDir == RIGHT || curDir == LEFT);
		forbiddenDir = NONE;
	}
	void collideWith(GameObject* other);
	enum action isDead(void) const;
	void bonkMushroom(dir mushroomDir);
private:
	void genNewPosition(const sf::RenderWindow& window);
	void incrementDir(dir& d);
	void reverseDir(dir& d);
	dir horizDir; // whether we're going to the left across this row or right - swaps every time we go down
	dir vertGoalDir; // determines whether we're going up or down the screen
	dir forbiddenDir;
	bool movingHorizontal;
};