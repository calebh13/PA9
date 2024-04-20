#pragma once
#include "GameObject.hpp"

class Bullet : public GameObject
{
public:
	Bullet(unsigned int scale = 1, const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1, unsigned int interpolationFrames = 1)
		: GameObject(scale, pos, texture, health, interpolationFrames)
	{
		// Make all bullets centered
		this->setOrigin((float)texture.getSize().x / 2, (float)texture.getSize().y / 2);
	}
};