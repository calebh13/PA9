#pragma once
#include "GameObject.hpp"

class Bullet : public GameObject
{
public:
	using GameObject::GameObject;

	
	void shoot();
	// bullet speed 
	float getSpeedMult() const;
};