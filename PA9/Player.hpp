#pragma once
#include "GameObject.hpp"

class Player : public GameObject
{
public:
	Player(const sf::Vector2f& scale = sf::Vector2f(1, 1), const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1, unsigned int speed = 20, unsigned int lives = 5) 
		: GameObject(scale, pos, texture, health, speed)
	{
		this->lives = lives;
	}
	
	void hit();
	bool isDead() const;
protected:
	float getSpeedMult() const;
private:
	unsigned int lives;
};