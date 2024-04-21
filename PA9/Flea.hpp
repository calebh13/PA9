#pragma once
#include "GameObject.hpp"

class Flea : public GameObject
{
public:
	using GameObject::GameObject;
	// Fleas don't do anything other than drop down, and they only collide w/ the player
	void collideWith(GameObject* other);
};