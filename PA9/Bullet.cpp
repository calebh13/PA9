#include "Bullet.hpp"

void Bullet::shoot()
{
	this->glideTo(this->getPosition().x, this->getPosition().y - 10 * this->getSpeedMult());
	this->setPosition(this->getNextMovement());
}