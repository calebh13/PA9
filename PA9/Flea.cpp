#include "Flea.hpp"

void Flea::hit()
{
	health = 0;
}

bool Flea::isDead() const
{
	return health == 0;
}

float Flea::getSpeedMult() const
{
	// Need to adjust this later
	return 0.2f;
}
