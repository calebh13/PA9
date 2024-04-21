#pragma once
#include "GameObject.hpp"

void GameObject::hit(void)
{
	health -= 1;
}
bool GameObject::isDead(void) const
{
	return health == 0;
}


//********************************************************\\
//Created 4/15 by Lucas
//Takes in two coordinates, x and y, to which the object will move towards in discrete steps.
//The Object will start at its current position and then glide towards the new position
void GameObject::glideTo(float x, float y) {
	//Two Vectors that hold the x and y coordinates for each step
	movementInstructions = std::vector<sf::Vector2f>(interpolationFrames);

	const sf::Vector2f& currentPosition = this->getPosition();

	for (int i = 1; i <= interpolationFrames; i++) {
		movementInstructions[i - 1].x = currentPosition.x + (float)i * ((x - currentPosition.x) / interpolationFrames);
		movementInstructions[i - 1].y = currentPosition.y + (float)i * ((y - currentPosition.y) / interpolationFrames);
	}

	//When given new instructions, the object resets to the first frame of movement
	moveFrame = -1;
}

//Sets the objects position to its next movement location
void GameObject::update(const sf::RenderWindow& window) {
	// We will need to generate new instructions once we have been moving for time equal to interpolationFrames
	if (moveFrame < interpolationFrames) {
		moveFrame++;
	} else {
		genNewPosition(window);
	}
	this->setPosition(movementInstructions[moveFrame % interpolationFrames]);

}

void GameObject::heal(void)
{
	return;
}

//*********************************************************\\

// Should be overridden
void GameObject::genNewPosition(const sf::RenderWindow& window)
{
	movementInstructions[0] = sf::Vector2f(0, 0);
}
