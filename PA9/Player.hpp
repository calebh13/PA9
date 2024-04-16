#pragma once
#include "GameObject.hpp"
#include <iostream>
#define MAX_X 1000
#define MAX_Y 1000
#define MIN_Y 750

class Player : public GameObject
{
public:
	Player(const sf::Vector2f& scale = sf::Vector2f(1, 1), const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 0, unsigned int lives = 5) : GameObject(scale, pos, texture, health)
	{
		this->lives = lives;
	}
	
	void hit();
	bool isDead() const;
	void move(sf::RenderWindow &gameWindow);
protected:
	float getSpeedMult() const;
private:
	unsigned int lives;
	sf::Vector2i mousePosition;
	sf::Vector2f mouseVisual;
};