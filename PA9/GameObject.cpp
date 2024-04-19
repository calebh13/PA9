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
	std::cout << currentPosition.x << "\n";

	for (int i = 1; i <= interpolationFrames; i++) {
		movementInstructions[i - 1].x = currentPosition.x + (float)i * ((x - currentPosition.x) / interpolationFrames);
		movementInstructions[i - 1].y = currentPosition.y + (float)i * ((y - currentPosition.y) / interpolationFrames);
	}

	//When given new instructions, the object resets to the first frame of movement
	moveFrame = -1;
}

//Sets the objects position to its next movement location
void GameObject::update() {
	this->setPosition(getNextPos());
}

//*********************************************************\\

//Returns the next location the sprite should be drawn at in its movement cycle
sf::Vector2f GameObject::getNextPos() {
	if (!movementInstructions.empty()) {
		moveFrame++;
		return movementInstructions[moveFrame];// % (interpolationFrames)];
	}
	else {
		std::cout << "ERROR: no movement instructions!";
		throw std::exception();
	}
}