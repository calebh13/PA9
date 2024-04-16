#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
//The number of discrete steps in an objects movement
#define INTERPOLATION_FRAMES 10

class GameObject : public sf::Sprite
{
public:
	GameObject(const sf::Vector2f& scale = sf::Vector2f(1, 1), const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1) : sf::Sprite(texture)
	{
		this->setScale(scale);
		this->setPosition(pos);
		this->health = health;
		this->movementInstructions = std::vector<sf::Vector2f>(INTERPOLATION_FRAMES);
		this->moveFrame = -1;
	}
	virtual void hit(void) = 0; 
	virtual bool isDead(void) const = 0;
	void move(const sf::Vector2f& dir, float dt)
	{
		sf::Vector2f offset = sf::Vector2f(dir.x * dt * getSpeedMult(), dir.y * dt * getSpeedMult());
		this->sf::Transformable::move(offset);
	}


	//********************************************************\\
	//Created 4/15 by Lucas
	//Takes in two coordinates, x and y, to which the object will move towards in discrete steps.
	//The Object will start at its current position and then glide towards the new position
	void glideTo(float x, float y) {
		//Two Vectors that hold the x and y coordinates for each step
		movementInstructions = std::vector<sf::Vector2f>(INTERPOLATION_FRAMES);

		auto currentPosition = this->getPosition();
		std::cout << currentPosition.x << "\n";

		for (int i = 1; i <= INTERPOLATION_FRAMES; i++) {
			movementInstructions[i - 1].x = currentPosition.x + (float)i * ((x - currentPosition.x) / INTERPOLATION_FRAMES);
			movementInstructions[i - 1].y = currentPosition.y + (float)i * ((y - currentPosition.y) / INTERPOLATION_FRAMES);
		}

		//When given new instructions, the object resets to the first frame of movement
		moveFrame = -1;
	}
	
	//Sets the objects position to its next movement location
	void update() {
		this->setPosition(getNextMovement());
	}

	//Returns the movement steps of object
	std::vector<sf::Vector2f> getInstructions() {
		return movementInstructions;
	}

	//*********************************************************\\

protected:
	unsigned int health;
	// everything has a constant movement speed,
	// so speed is essentially a multiplier for all objects of this type
	virtual float getSpeedMult(void) const = 0;

	//Collection of movements and the frame at which it is moving
	std::vector<sf::Vector2f> movementInstructions;
	int moveFrame;

	//Returns the next location the sprite should be drawn at in its movement cycle
	sf::Vector2f getNextMovement() {
		if (!movementInstructions.empty()) {
			moveFrame++;
			return movementInstructions[moveFrame % (INTERPOLATION_FRAMES)];
		}
		else {
			return sf::Vector2f();
		}
	}
};