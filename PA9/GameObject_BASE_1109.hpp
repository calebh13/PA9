#pragma once
#include <SFML/Graphics.hpp>

class GameObject : public sf::Sprite
{
public:
	GameObject(const sf::Vector2f& scale = sf::Vector2f(1, 1), const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1) : sf::Sprite(texture)
	{
		this->setScale(scale);
		this->setPosition(pos);
		this->health = health;
	}
	virtual void hit(void) = 0; 
	virtual bool isDead(void) const = 0;
	void move(const sf::Vector2f& dir, float dt)
	{
		sf::Vector2f offset = sf::Vector2f(dir.x * dt * getSpeedMult(), dir.y * dt * getSpeedMult());
		this->sf::Transformable::move(offset);
	}
protected:
	unsigned int health;
	// everything has a constant movement speed,
	// so speed is essentially a multiplier for all objects of this type
	virtual float getSpeedMult(void) const = 0;
};