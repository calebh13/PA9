#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class GameObject : public sf::Sprite
{
public:
	GameObject(unsigned int scale = 1, const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1, unsigned int INTERPOLATION_FRAMES = 10) : sf::Sprite(texture)
	{
		this->setScale(scale, scale);
		this->setPosition(pos);
		this->health = health;
		this->movementInstructions = std::vector<sf::Vector2f>(INTERPOLATION_FRAMES);
		this->moveFrame = -1;
		//The number of discrete steps in an objects movement to any given point
		this->INTERPOLATION_FRAMES = INTERPOLATION_FRAMES;
	}
	virtual void hit(void);
	virtual bool isDead(void) const;

	void move(const sf::Vector2f& dir, float dt);

	//********************************************************\\
	//Created 4/15 by Lucas
	//Takes in two coordinates, x and y, to which the object will move towards in discrete steps.
	//The Object will start at its current position and then glide towards the new position
	void glideTo(float x, float y);
	
	//Sets the objects position to its next movement location
	void update();

	//Returns the movement steps of object
	std::vector<sf::Vector2f> getInstructions();

	//*********************************************************\\

protected:
	unsigned int health;
	unsigned int INTERPOLATION_FRAMES;
	//Collection of movements and the frame at which it is moving
	std::vector<sf::Vector2f> movementInstructions;
	int moveFrame;

	//Returns the next location the sprite should be drawn at in its movement cycle
	sf::Vector2f getNextMovement();

	virtual float getSpeedMult(void) const;
};