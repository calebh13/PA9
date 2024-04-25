/*
	Jace, Lucas

	Description: This is the header file for the Spider Class

   History: 4/19/24 - Class was created and implimented initially by Jace
			4/21/24 - Code refactored by Lucas

*/
#pragma once
#include "GameObject.hpp"
#include <time.h>
#include "Bullet.hpp"

//Spiders inherit gameObject
class Spider : public GameObject
{
public:
	Spider(unsigned int scale = 1, const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1, unsigned int speed = 10) 
		: GameObject(scale, pos, texture, health, speed)
	{

	}
	// hit and isDead is inherited from GameObject 
	void collideWith(GameObject* other);
	void genNewPosition(const sf::RenderWindow& window);

	//Spiders move in random directions
	void genRandomDir();

private:
	//Spiders have cooldowns on their movement
	const float moveCoolDown = 2.0f;
	int xDir, yDir;
};