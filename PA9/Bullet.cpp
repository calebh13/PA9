#include "Bullet.hpp"

float Bullet::getSpeedMult() const
{
	// Need to adjust this later
	return 20.0f;
}

void Bullet::shoot()
{
	this->glideTo(this->getPosition().x, this->getPosition().y - 10 * this->getSpeedMult());
	this->setPosition(this->getNextMovement());
}