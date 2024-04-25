/*
	Lucas, Caleb, Jace

	Description: This is a header file that defines the GameObject class. 

// History: 4/18/24 - Class was created and implimented initially by Caleb
			4/19/24 - GlideTo, Update, and genNewPosition implimented by Lucas
			4/20/24 - genNewPosition modified by Jace
			4/22/24 - collideWith and isDead added by Caleb
			4/23/24 - Action enum added by Caleb

*/
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

//Enum containing all the actions a gameObject can have
enum action
{
	NOTHING, DESTROY, RESPAWN, SPLIT_CENTIPEDE, CENTIPEDE_HEAD_MOVE, CENTIPEDE_DESTROYED, GAME_OVER
};

//GameObject inherits Sprite
class GameObject : public sf::Sprite
{
public:
	//Constructor. Sets initial size, position, and health
	GameObject(unsigned int scale = 1, const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1, unsigned int interpolationFrames = 1) : sf::Sprite(texture)
	{
		this->setScale(scale, scale);
		this->setPosition(pos);
		this->health = health;
		this->movementInstructions = std::vector<sf::Vector2f>(interpolationFrames);
		this->moveFrame = -1;
		// The number of discrete steps in an objects movement to any given point
		this->interpolationFrames = interpolationFrames;
	}
	
	//Performs actions when hit by another entity
	virtual void hit(void);

	//Returns information on death status
	virtual enum action isDead(void) const;

	//Pure virtual. Every entity crashes in different ways
	virtual void collideWith(GameObject* other) = 0;


	//Takes in two coordinates, x and y, to which the object will move towards in discrete steps.
	//The Object will start at its current position and then glide towards the new position
	void glideTo(float x, float y);
	
	//Sets the objects position to its next movement location
	void update(const sf::RenderWindow& window);

	// only really needed for mushroom. Resets an objects health to full
	void heal(void);

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