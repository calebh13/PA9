#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class GameObject : public sf::Sprite
{
public:
	GameObject(unsigned int scale = 1, const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1, unsigned int interpolationFrames = 1) : sf::Sprite(texture)
	{
		this->setScale(scale, scale);
		this->setPosition(pos);
		this->health = health;
		this->movementInstructions = std::vector<sf::Vector2f>(interpolationFrames);
		this->moveFrame = -1;
		//The number of discrete steps in an objects movement to any given point
		this->interpolationFrames = interpolationFrames;
	}
	virtual void hit(void);
	virtual bool isDead(void) const;

	//********************************************************\\
	//Created 4/15 by Lucas
	//Takes in two coordinates, x and y, to which the object will move towards in discrete steps.
	//The Object will start at its current position and then glide towards the new position
	void glideTo(float x, float y);
	
	//Sets the objects position to its next movement location
	virtual void update(const sf::RenderWindow& window);

	//*********************************************************\\

protected:
	unsigned int health;
	unsigned int interpolationFrames;
	//Collection of movements and the frame at which it is moving
	std::vector<sf::Vector2f> movementInstructions;
	int moveFrame;


	// Generates a new position according to the object's internal movement logic
	// Thus this function should be overridden for all classes
	virtual void genNewPosition(const sf::RenderWindow& window);
};