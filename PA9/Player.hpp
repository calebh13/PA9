#pragma once
#include "GameObject.hpp"
#include <Windows.h>

#define PLAYER_SPEED 20

class Player : public GameObject
{
public:
	Player(unsigned int scale = 1, const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1, unsigned int speed = 1, unsigned int lives = 5) 
		: GameObject(scale, pos, texture, health, speed)
	{
		this->lives = lives;
		this->shotCooldown = 0;
		this->lastValidPosition = pos;
	}
	
	void hit();
	enum action isDead() const;
	bool shoot(void);
	void reduceShotTimer(void);

	void returnToValidPos(void);

	void collideWith(GameObject* other);

private:
	unsigned int lives;
	unsigned int shotCooldown;
	sf::Vector2i mousePosition;
	sf::Vector2f mouseVisual;
	sf::Vector2f lastValidPosition;
	void genNewPosition(const sf::RenderWindow& window) override;
};