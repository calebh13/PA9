/*
	Caleb, Lucas, Jace

	Description: This is the header file for the Player Class

   History: 4/17/24 - Class was created initially by Lucas with rudamentary movement
			4/19/24 - Movement refactored and shots added by Jace
			4/20/24 - Collision added by Caleb

*/

#pragma once
#include "GameObject.hpp"
#include <Windows.h>

//Speed of the plaer
#define PLAYER_SPEED 20

//Players inherit GameObject
class Player : public GameObject
{
public:
	Player(unsigned int scale = 1, const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1, unsigned int speed = 1, unsigned int lives = 5) 
		: GameObject(scale, pos, texture, health, speed)
	{
		//Lives, cooldown, and initial position is set
		this->lives = lives;
		this->shotCooldown = 0;
		this->lastValidPosition = pos;
	}
	
	//Functions inherited by GameObject
	void hit();
	enum action isDead() const;
	void returnToValidPos(void);
	void collideWith(GameObject* other);
	void heal(void);

	//Functions around shooting
	bool shoot(void);
	void reduceShotTimer(void);

	unsigned int getRespawnCooldown(void) const;
	void setRespawnCooldown(unsigned int cooldown);
	void reduceRespawnCooldown(void);

private:
	//Private variables around movement and shooting
	unsigned int lives;
	unsigned int shotCooldown;
	unsigned int respawnCooldown;
	sf::Vector2i mousePosition;
	sf::Vector2f mouseVisual;
	sf::Vector2f lastValidPosition;
	void genNewPosition(const sf::RenderWindow& window) override;
};