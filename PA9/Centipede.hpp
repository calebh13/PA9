#pragma once
#include "GameObject.hpp"
#include "CentipedeHead.hpp"
#include "CentipedeBody.hpp"
class Centipede : public GameObject
{
	// Composite object, composed of CentipedeHead and CentipedeBody
	// need to override the draw functions for the vector
public:
	// Need to figure out constructor: all CentipedeHead 
	using GameObject::GameObject;
private:
	unsigned int length;
	float speed; // centipede is the only thing that changes speed
	CentipedeHead* head;
	std::vector<CentipedeBody*> body;
};