#pragma once
#include "CentipedeHead.hpp"
#include "CentipedeBody.hpp"
class Centipede
{
	// Composite object, composed of CentipedeHead and CentipedeBody
	// need to override the draw() function for Centipede, because we have to draw the head and body
	// probably need to override even more functions to handle multiple centipedes
public:
	Centipede(unsigned int length, unsigned int speed)
	{
		this->length = length;
		this->speed = speed;
		this->head = new CentipedeHead();
		body.resize(length - 1);
	}
private:
	unsigned int length;
	unsigned int speed; // centipede is the only thing that changes speed
	CentipedeHead* head;
	std::vector<CentipedeBody*> body;
};