/*
	Caleb
	
	Description: Header File for centipede head

// History: 4/24/24 - Class was created and implimented initially by Caleb

*/
#pragma once
#include "GameObject.hpp"
#include "Grid.hpp"
#include "CentipedePart.hpp"

//Inherits from centipede part
class CentipedeHead : public CentipedePart
{

public:
	//Constructor
	CentipedeHead(unsigned int scale = 1, const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1, unsigned int interpolationFrames = 10, dir curDir = RIGHT,
		dir horizDir = RIGHT, dir vertGoalDir = DOWN) : CentipedePart(scale, pos, texture, health, interpolationFrames, curDir)
	{
		this->health = 5;
		this->horizDir = horizDir;
		this->vertGoalDir = vertGoalDir;
		movingVertically = (curDir == UP || curDir == DOWN);
	}

	//Overloaded from GameObject
	void collideWith(GameObject* other);
	enum action isDead(void) const;
	void bonkMushroom(dir mushroomDir);
	bool isMovingVertically(void) const;
	dir getHorizDir(void) const;
	dir getVertDir(void) const;

private:
	void genNewPosition(const sf::RenderWindow& window);
	void incrementDir(dir& d);
	dir horizDir; // whether we're going to the left across this row or right - swaps every time we go down
	dir vertGoalDir; // determines whether we're going up or down the screen
	bool movingVertically;
};