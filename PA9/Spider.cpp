#include "Spider.hpp"

float Spider::getSpeedMult() const
{
	return 04.f; // not sure how to test the speed quite yet
}

void Spider::movement()
{
	// gen random direction 
	// gen random time 
	// repeat within bounds 
	float xDirection = 0, yDirection = 0;
	
	while (!this->isDead())
	{
		xDirection = rand();
		yDirection = rand();
		sf::Vector2f direction(xDirection, yDirection);
		

		for () // some length of time 
		{
			this->move(direction);
		}

	}
			
}