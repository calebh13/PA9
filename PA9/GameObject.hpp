#pragma once
#include <SFML/Graphics.hpp>

class GameObject : public sf::Sprite
{
public:
	GameObject(const sf::Vector2f& scale = sf::Vector2f(1, 1), const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 0) : sf::Sprite(texture)
	{
		this->setScale(scale);
		this->setPosition(pos);
		this->health = health;
	}
	virtual void hit() = 0;
protected:
	unsigned int health;
};