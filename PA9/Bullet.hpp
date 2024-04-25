/*
	Jace
	4/22/24

	Description: This is the header file for the bullet class

// History: 4/22/24 - Class was created and implimented initially

*/

//Header Guards and includes
#pragma once
#include "GameObject.hpp"
#include "CentipedeBody.hpp"
#include "Mushroom.hpp"
#include "Spider.hpp"
#include "CentipedeHead.hpp"
#include "Flea.hpp"

//Bullet inherits from GameObject.
class Bullet : public GameObject
{
public:
	//Bullets have standard game object constructors
	Bullet(unsigned int scale = 1, const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1, unsigned int interpolationFrames = 1)
		: GameObject(scale, pos, texture, health, interpolationFrames)
	{
		// Make all bullets centered
		this->setOrigin((float)texture.getSize().x / 2, (float)texture.getSize().y / 2);
	}

	//isDead() returns an enum of instructions for what to do with a gameObject
	//ex. a return value of DESTROY means this object should be deleted
	enum action isDead(void) const;

	//Makes the needed changes to each bullet object when colliding with other objects
	void collideWith(GameObject* other);
private:
	//Changes the bullets position based on frames
	void genNewPosition(const sf::RenderWindow& window);
};