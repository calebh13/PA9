#pragma once
#include "GameObject.hpp"
#include <Windows.h>

class Player : public GameObject
{
public:
	Player(const sf::Vector2f& scale = sf::Vector2f(1, 1), const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1, unsigned int speed = 5, unsigned int lives = 5) 
		: GameObject(scale, pos, texture, health, speed)
	{
		this->lives = lives;
		upVel = downVel = leftVel = rightVel = false;
	}
	
	void hit();
	bool isDead() const;
	void update() {
		if (GetKeyState('W') & 0x8000) {
			upVel = true;
		}
		else {
			upVel = false;
		}
		if (GetKeyState('A') & 0x8000) {
			leftVel = true;
		}
		else {
			leftVel = false;
		}
		if (GetKeyState('D') & 0x8000) {
			rightVel = true;
		}
		else {
			rightVel = false;
		}
		if (GetKeyState('S') & 0x8000) {
			downVel = true;
		}else {
			downVel = false;
		}
		this->glideTo(this->getPosition().x + (-leftVel + rightVel) * 10, this->getPosition().y + (-upVel + downVel) * 10);
		this->setPosition(getNextMovement());
	}

protected:
	float getSpeedMult() const;
private:
	unsigned int lives;
	bool leftVel, rightVel, upVel, downVel;
};

//Player box is 5 cells tall and as wide as the screen