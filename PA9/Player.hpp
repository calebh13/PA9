#pragma once
#include "GameObject.hpp"
#include <Windows.h>

#define PLAYER_SPEED 20

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

	//Added by Lucas 4/16
	//Overrided update method for Player Object. Checks whether the player is moving and changes 
	//Velocity Accordingly
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

		//Glides from the player's current position to the direction of highest velocity in x and y
		this->glideTo(this->getPosition().x + (-leftVel + rightVel) * PLAYER_SPEED, this->getPosition().y + (-upVel + downVel) * PLAYER_SPEED);
		this->setPosition(getNextMovement());	}

protected:
	float getSpeedMult() const;
private:
	unsigned int lives;
	//Store whether the player is moving up,down,left,or right at any given moment
	bool leftVel, rightVel, upVel, downVel;
};

//Player box is 5 cells tall and as wide as the screen