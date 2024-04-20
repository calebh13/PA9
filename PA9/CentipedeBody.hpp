#pragma once
#include "GameObject.hpp"

class CentipedeBody : public GameObject
{
public:
	using GameObject::GameObject;
	// these guys just follow the centipede in front of them
private:
	int dir;
};