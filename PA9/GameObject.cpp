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
void GameObject::move(const sf::Vector2f& dir, float dt)
{
	sf::Vector2f offset = sf::Vector2f(dir.x * dt * getSpeedMult(), dir.y * dt * getSpeedMult());
	this->sf::Transformable::move(offset);
}


//********************************************************\\
//Created 4/15 by Lucas
//Takes in two coordinates, x and y, to which the object will move towards in discrete steps.
//The Object will start at its current position and then glide towards the new position
void GameObject::glideTo(float x, float y) {
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
void GameObject::update() {
	this->setPosition(getNextMovement());
}

//Returns the movement steps of object
std::vector<sf::Vector2f> GameObject::getInstructions() {
	return movementInstructions;
}

//*********************************************************\\

//Returns the next location the sprite should be drawn at in its movement cycle
sf::Vector2f GameObject::getNextMovement() {
	if (!movementInstructions.empty()) {
		moveFrame++;
		return movementInstructions[moveFrame % (INTERPOLATION_FRAMES)];
	}
	else {
		return sf::Vector2f();
	}
}
float GameObject::getSpeedMult(void) const
{
	return 0.0f;
}