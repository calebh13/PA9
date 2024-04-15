#pragma once
#include "GameObject.hpp"

class Flea : public GameObject
{
public:
	using GameObject::GameObject; // inherit constructor
	void hit();
	bool isDead() const;
protected:
	float getSpeedMult() const;
	// Fleas don't do anything other than drop down, and they only collide w/ the player
};