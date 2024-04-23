#pragma once
#include "GameObject.hpp"

class Player : public GameObject
{
public:
	Player(unsigned int scale = 1, const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1, unsigned int speed = 1, unsigned int lives = 5) 
		: GameObject(scale, pos, texture, health, speed)
	{
		this->lives = lives;
		this->shotCooldown = 0;
	}
	
	void hit();
	enum action isDead() const;
	bool shoot(void);
	void reduceShotTimer(void);

	void collideWith(GameObject* other);

//protected: // speed not needed as player speed is constant and matches mouse speed 
//	float getSpeedMult() const;
private:
	unsigned int lives;
	unsigned int shotCooldown;
	sf::Vector2i mousePosition;
	sf::Vector2f mouseVisual;
	void genNewPosition(const sf::RenderWindow& window) override;
};