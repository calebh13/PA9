#pragma once
#include "GameObject.hpp"

class Mushroom : public GameObject
{
public: 
	using GameObject::GameObject; // inherit constructor
	void hit();
	bool isDead() const;
protected:
	float getSpeedMult() const;
};