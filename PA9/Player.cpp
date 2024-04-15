#include "Player.hpp"

void Player::hit()
{
	lives -= 1;
	// maybe do some animation stuff as well, not sure where that should happen exactly
}

bool Player::isDead() const
{
	return lives == 0;
}

float Player::getSpeedMult() const
{
	return 0.2f;
}
