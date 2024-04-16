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
	std::srand(std::time(nullptr));
	float xDirection = 0, yDirection = 0;
	
	while (!this->isDead())
	{
		xDirection = ((float)rand()/1) * 2 - 1;
		yDirection = ((float)rand()/1) * 2 - 1;
		sf::Vector2f direction(xDirection, yDirection); // a vector going in a random direction 

		// Generate random time
		sf::Clock timer;
		sf::Time elapsedTime;
		elapsedTime = sf::milliseconds(rand() % 1500 + 500);

		while (timer.getElapsedTime() < elapsedTime)
		{
			// the glide
		}

	}
			
}