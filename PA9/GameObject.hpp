#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class GameObject : public sf::Sprite
{
public:
	GameObject(unsigned int scale = 1, const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1, unsigned int interpolationFrames = 10) : sf::Sprite(texture)
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
	
	// TODO: Make this take a const sf::RenderWindow& and use that to generate next positions
	// this is required for the player so it'll probably be required for everything else because positions are all relative to the window
	void update();

	//*********************************************************\\

protected:
	unsigned int health;
	unsigned int interpolationFrames;
	//Collection of movements and the frame at which it is moving
	std::vector<sf::Vector2f> movementInstructions;
	int moveFrame;

	//Returns the next location the sprite should be drawn at in its movement cycle
	sf::Vector2f getNextPos();
	void genNewPosition();
};