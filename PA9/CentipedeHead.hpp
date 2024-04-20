#pragma once
#include "GameObject.hpp"
#include "Centipede.hpp"

class CentipedeHead : public GameObject
{
public:
	using GameObject::GameObject;
	// this is where logic for determining next move goes
private:
	int dir;
};