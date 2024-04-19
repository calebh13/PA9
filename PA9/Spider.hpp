#pragma once
#include "GameObject.hpp"
#include <time.h>

class Spider : public GameObject
{
public:
	Spider(unsigned int scale = 1, const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1, unsigned int speed = 10) 
		: GameObject(scale, pos, texture, health, speed)
	{

	}
	// hit and isDead is inherited from GameObject 

};