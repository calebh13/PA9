#pragma once
#include "GameObject.hpp"

class Spider : public GameObject
{
public:
	Spider(const sf::Vector2f& scale = sf::Vector2f(1, 1), const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1, unsigned int speed = 10) 
		: GameObject(scale, pos, texture, health, speed)
	{
		// change collision box here?
	}
};