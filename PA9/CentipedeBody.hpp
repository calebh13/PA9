#pragma once
#include "GameObject.hpp"
#include "Bullet.hpp"

class CentipedeBody : public GameObject
{
public:
	using GameObject::GameObject;
	// these guys just follow the centipede in front of them
	void collideWith(GameObject* other);
private:
	int dir;
};