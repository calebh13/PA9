#pragma once
#include "CentipedeHead.hpp"
#include "CentipedeBody.hpp"
class Centipede
{
	// Composite object, composed of CentipedeHead and CentipedeBody
	// need to override the draw functions for the vector
public:
	// Need to figure out constructor: all CentipedeHead 
	Centipede(unsigned int length, float speed)
	{
		this->length = length;
		this->speed = speed;
		this->head = new CentipedeHead();
		body.resize(length - 1);
	}
private:
	unsigned int length;
	float speed; // centipede is the only thing that changes speed
	CentipedeHead* head;
	std::vector<CentipedeBody*> body;
};