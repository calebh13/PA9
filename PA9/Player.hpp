#pragma once
#include "GameObject.hpp"
#include "Bullet.hpp"
#include <iostream>
#define MAX_X 1500
#define MAX_Y 1500
#define MIN_Y 1250

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
	void move(sf::RenderWindow &gameWindow);
	void shoot(Bullet &bullets);

//protected: // speed not needed as player speed is constant and matches mouse speed 
//	float getSpeedMult() const;
private:
	unsigned int lives;
	sf::Vector2i mousePosition;
	sf::Vector2f mouseVisual;
};