#pragma once
#include "GameObject.hpp"
#include "Centipede.hpp"
#include "Bullet.hpp"

class CentipedeHead : public GameObject
{
public:
	using GameObject::GameObject;
	// this is where logic for determining next move goes
	void collideWith(GameObject* other);
private:
	int dir;

	//void genNewPosition(const sf::RenderWindow& window);
};