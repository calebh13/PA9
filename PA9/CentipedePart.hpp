/*
	Caleb

	Description: Header File for centipede Part

// History: 4/24/24 - Class was created and implimented initially by Caleb

*/
#pragma once
#include "GameObject.hpp"


//Enum for movement Directions
enum dir
{
	UP, RIGHT, DOWN, LEFT, NONE
};

//Centipede parts are gameobjects
class CentipedePart : public GameObject
{
public:
	//Constructor
	CentipedePart(unsigned int scale = 1, const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1, unsigned int interpolationFrames = 10, 
		dir curDir = dir::RIGHT) : GameObject(scale, pos, texture, health, interpolationFrames)
	{
		this->curDir = curDir;
		this->nodeBehind = nullptr;
		this->lastWaypoint = pos;
	}
	
	//Overloaded from GameObject
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